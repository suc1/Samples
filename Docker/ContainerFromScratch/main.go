package main

//https://docs.docker.com/get-started/

import (
	"fmt"
	"os"
	"os/exec"
	"syscall"
)

//docker				run image <cmd> <params>
//go run main.go 		run		  <cmd> <params>

func main() {
	switch os.Args[1] {
	case "run":
		run()
	default:
		panic("bad command")
	}
}

func run() {
	fmt.Printf("Running %v\n", os.Args[2:])

	cmd := exec.Command(os.Args[2], os.Args[3:]...)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.SysProcAttr = &syscall.SysProcAttr{
		Cloneflags: syscall.CLONE_NEWUTS,
	}

	cmd.Run() //no output in win???
}

func must(err error) {
	if err != nil {
		panic(err)
	}
}
