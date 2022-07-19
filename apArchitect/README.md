# 深蓝学院 - 自动驾驶基础构架

## 上课资源
[上课](https://www.shenlanxueyuan.com/my/course/485)

## 第4章 Devops 自动化实践CI/CD
1. [Jenkins](https://www.jenkins.io/)
2. [Gitlab-CI](https://docs.gitlab.com/ee/ci/)
3. [bazel: remote cache](https://bazel.build/)
4. [cmake: ninja, ccache + redis](https://cmake.org/)
5. Code analysis: Sonarqube, Clang-tidy, [Cppcheck](https://cppcheck.sourceforge.io/), [Cppdepend](https://www.cppdepend.com/)
6. Unit Test: GTest, pytest, GoTest, Java Junit
7. [CD: Nexus: pypi, debian, docker image](https://help.sonatype.com/integrations/nexus-and-continuous-integration)
8. [CD: Harbor](https://goharbor.io/blog/harbor-1.9/)
9. 蓝绿部署，灰度发布，滚动部署


## 软件资源: Git submodule D:\sample\ThirdPartyLib\
1. [cpp-httplib
](https://github.com/yhirose/cpp-httplib.git)
2. [hash-library](https://github.com/stbrumme/hash-library)

## 第2章作业:数据的产生: home2data_generate
命令在command.txt

## 第3章作业:数据的采集和存储: home3dataCollectStore
1. 局限: 客户端和服务器端只支持一个链接，最好改成多个链接
2. 局限: 服务器端支持多文件上载
3. http传输需要校验吗？
4. chunkSize一开始就固定死。如果改变需要删掉*.conf，然后运行
5. Client side: *.hash智能判断修改
6. *.conf需要把hash值改成上传文件名，并且存hash值
7. WriteFile.py 产生50G文件
8. 4.2G文件: 创建文件1.3Min, 产生Hash耗时58 秒，传输文件耗时16分钟