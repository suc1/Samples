# Go资源
[Go tutorial](https://go.dev/doc/tutorial/)

## command
```
cd D:\sample\Go\hello
go mod init example/hello
go mod tidy

go run .
```
```
go mod edit -replace example.com/greetings=../greetings
go mod tidy
```
```
go test
go test -v
```
```
go build
go list -f '{{.Target}}'

export PATH=$PATH:
set PATH=%PATH%;"C:\Users\Su Cheng\go\bin"
go env -w GOBIN=

go install

```
## note
1. packages -> modules