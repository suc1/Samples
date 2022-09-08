package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

	"context"
	//"log"
	"go.etcd.io/etcd/client/v3"
	"time"
	//"strconv"
)

const (
	//ToDo: Fix "panic: context deadline exceeded"?????????????????
	DIAL_TIMEOUT    	= 200 * time.Second		//2
	REQUEST_TIMEOUT 	= 1000 * time.Second	//10
	SRV_TIMEOUT			= 2

	TOPIC 				= "/discovery"
	PREFIX 				= "srv"

	KEY_NAME			= TOPIC + "/" + PREFIX
)

////Service Side
func Service(ctx context.Context, cli *clientv3.Client, kv clientv3.KV, clientNo string) {
	fmt.Println("Press Ctrl-C to exit/crash this Service ")

	lease, err := cli.Grant(ctx, SRV_TIMEOUT)
	if err != nil {
		panic(err)
	}

	keyName := KEY_NAME + clientNo
	/*
	_ , err := kv.Put(ctx,  keyName, "IP:port", clientv3.WithLease(lease.ID))
	if err != nil {
		panic(err)
	}
	*/
	//ToDo: make nice for err??
	kv.Put(ctx,  keyName, "IP:port", clientv3.WithLease(lease.ID))
	
	/*
	gr, err := kv.Get(ctx, keyName)
	if err != nil {
		panic(err)
	}
	fmt.Println("Value: ", string(gr.Kvs[0].Value), "Revision: ", gr.Header.Revision)
	*/

	for {
		_, err := cli.KeepAliveOnce(ctx, lease.ID)
		if err != nil {
			panic(err)			
		}
		//fmt.Println(lease.String())
		time.Sleep(SRV_TIMEOUT/2.0 * time.Second)
	}
}

////Gateway Side
func Gateway(ctx context.Context, cli *clientv3.Client, kv clientv3.KV) {
	fmt.Println("Press enter to exit gateway")

	opts := []clientv3.OpOption{
		clientv3.WithPrefix(),
		//clientv3.WithSort(clientv3.SortByKey, clientv3.SortAscend),
		//clientv3.WithLimit(10),
	}

	gr, err := kv.Get(ctx, KEY_NAME, opts...)
	if err != nil {
		panic(err)
	}

	fmt.Println("\nExist services:")
	for _, item := range gr.Kvs {
		fmt.Println(string(item.Key), " = ", string(item.Value))
	}

	//watch all changes
	stopChan := make(chan interface{})
	go func() {
		watchChan := cli.Watch(ctx, KEY_NAME, clientv3.WithPrefix())
		for true {
			select {
			case result := <-watchChan:
				fmt.Println("\nServices Change:")
				for _, ev := range result.Events {
					fmt.Printf("%s %q : %q\n", ev.Type, ev.Kv.Key, ev.Kv.Value)
				}
			case <-stopChan:
				fmt.Println("Done watching.")
				return
			}
		}
	}()

	fmt.Scanln()
	stopChan <- 1
}

func main() {
	fmt.Println("模型是一个gateway后面接多个service")
	fmt.Print("Pls run: 0-gateway, 1-srv1, 2-srv2... :")
	reader := bufio.NewReader(os.Stdin)
	clientNo, _ := reader.ReadString('\n')
	clientNo = strings.Replace(clientNo, "\n", "", -1)
	clientNo = strings.Replace(clientNo, "\r", "", -1)	//windows
	
	ctx, _ := context.WithTimeout(context.Background(), REQUEST_TIMEOUT)
	cli, err := clientv3.New(clientv3.Config{
		DialTimeout: DIAL_TIMEOUT,
		Endpoints: []string{"0.0.0.0:2379"},
		})
	if err != nil {
		panic(err)
	}
	defer cli.Close()

	kv := clientv3.NewKV(cli)
	if clientNo=="0" {
		Gateway(ctx, cli, kv)
	} else {
		Service(ctx, cli, kv, clientNo)
	}
}
