# 深蓝学院 - 自动驾驶基础构架

## 上课资源
[上课](https://www.shenlanxueyuan.com/my/course/485)

## 软件资源: Git submodule D:\sample\ThirdPartyLib\
1. [cpp-httplib
](https://github.com/yhirose/cpp-httplib.git)
2. [hash-library](https://github.com/stbrumme/hash-library)

## 第3章作业:数据的采集和存储
1. 局限: 客户端和服务器端只支持一个链接，最好改成多个链接
2. 局限: 服务器端支持多文件上载
3. http传输需要校验吗？
4. chunkSize一开始就固定死。如果改变需要删掉*.conf，然后运行
5. Client side: *.hash智能判断修改
6. *.conf需要把hash值改成上传文件名，并且存hash值