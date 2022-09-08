# Install use
1. [ETCD介绍—etcd概念及原理方面分析](https://zhuanlan.zhihu.com/p/405811320)
2. [python-etcd3](https://python-etcd3.readthedocs.io/en/latest/installation.html#stable-release)

## 服务注册与发现
1. etcd2 中引入的 etcd/raft 库. http + json
2. etcd3 中引入的多版本控制、事务等功能. gRPC + protobuf
3. 分布式系统中的数据分为控制数据和应用数据. 对于应用数据，只推荐数据量很小，但是更新访问频繁的情况
4. 高可用，强一致性，小型KV数据存储服务

## 服务注册
1. 生成租约（lease grant）
2. 注册入口（put –lease）
3. 健康检查（keep alive）

## 服务发现
1. 获取入口（get）
2. 监听变动（watch）

## 应用场景
1. 服务发现（Service Discovery）
2. 消息发布与订阅
3. 负载均衡
4. 分布式通知与协调
5. 分布式锁、分布式队列
6. 集群监控与Leader竞选

## Install
1. install golang
2. install etcd

## 分布式结构
1. 消息队列
2. RPC
3. 分布式文件系统
4. 分布式存储系统
5. 分布式API网关
6. Docker, K8S
7. etcd

## etcd构架
1. wal : Write Ahead Log
2. snapsshot: 数据同步
3. boltdb: KV存储

## Command
1. etcdctl put key value
2. etcdctl get/del key
3. etcdctl watch key
4. etcdctl txn i
5. value(k), create(k), mod(k)
6. raft_term: 任期; revision: 全局版本号; create_revision: 创建key时全局版本号; mod_revision: 修改key时全局版本号
7. 内存中，B树， key -> revision -> value; 磁盘中, B+树， revision -> value
8. lease: 多个key的过期
9. etcdctl lease grant 10
10. etcdctl put key val lease=ID
```
etcdctl put /discovery/s1 "0.0.0.0:2379"
etcdctl get /discovery/s1
etcdctl del /discovery/s1

etcdctl lease grant 10
etcdctl lease keep-alive ID
etcdctl lease list

etcdctl watch /discovery/s1
```

## Raft 算法
1. leader election
2. log replication
3. ["Raft - The Understandable Distributed Protocol" by Ben Johnson (2013)](https://youtu.be/ro2fU8_mr2w)
4. [Tech Talk - Raft, In Search of an Understandable Consensus Algorithm by Diego Ongaro](https://youtu.be/LAqyTyNUYSY)

## command
```
go mod init Home8/regFind
go mod tidy
go build .
go run .

```

## For this homework, 模型是一个gateway后面接多个service
```
go get "github.com/coreos/etcd/clientv3"
etcdctl get --prefix /discovery/srv
etcdctl lease list
etcdctl lease timetolive [ID]
```
## One run example
```
.\regFind.exe   //input: 1  //Run srv1
.\regFind.exe   //input: 0  //Run gateway   //output: Exist services:   /discovery/srv1  =  IP:port
.\regFind.exe   //input: 2  //Run srv2      //output: Services Change:  PUT "/discovery/srv2" : "IP:port"
kill srv2                                   //output: Services Change:  DELETE "/discovery/srv2" : ""
```