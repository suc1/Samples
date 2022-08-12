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
10.  .gitlab-ci.yml

## 第5章 基础设施自动化实践
弹性云服务器（Elastic Cloud Server，ECS）
云数据库RDS
云负载均衡（Server Load Balancer，简称SLB）
云内容分发网络CDN（全称Content Delivery Network）
虚拟私有云（Virtual Private Cloud）

Infrastructure As Code (IaC)
Packer创建镜像	13:22/32:42
```
wget https://releases.hashicorp.com/packer/1.8.0/packer_1.8.0_
```
Terraform IT基础架构自动化编排工具	16:57/32:42
```
```
ansible 自动化运维工具
saltstack 自动化软件，主要为c/s架构

## 第6章 仿真
1. 来源: 路测数据，场景编辑，随机生成

## 第7章 数据可视化
1. 仿真算法, 仿真平台, 工具链系统
2. 模型变换(Modeling Transformation)(平移，旋转-逆时针为正，剪切)
3. 观察变换(View Transformation)(世界坐标系->相机坐标系中)
4. 投影变换(Projection Transformation)(平行光 vs 小孔成像)
    1. 投射投影(perspective projection)(锥形投影:    透视-远小近大)
    2. 正交投影(orthographic projection)(长方体投影: 鸟瞰)
5. 视口变换(Viewport Transformation)(局部放缩)
6. 线性变换(scaling缩放, mirror镜像, shea剪切, rotation旋转)
7. 非线性变换(translation平移)
8. 仿射变换(=6+7)
9. 齐次坐标系(把仿射变换->线性变换), [点在末尾添加1，而向量在末尾添加0](https://www.aiuai.cn/aifarm1946.html)
10. 矩阵乘法结合律使用
11. 双向反射分布函数(Bidirectional Reflectance Distribution Function): 此点的光亮 = 此点的自发光 + 所有光源对此点的贡献
12. 着色模型：经验规律模型, 假想规律模型, 物理模型
13. Lambertian模型（漫反射着色模型）, Blinn-phone模型（高光反射模型）
14. 三角形, 栅格化
15. Z-buffer: Stencil buffer / Accumulation buffer / Multi-layer alpha blending
16. 抗走样(Anti-aliasing): 锯齿过渡柔和
17. 光线追踪

## 第8章 使用
1. 传统网关: Nginx; API网关: Kong, APISIX
2. 一致性协议包括 Raft, Paxos 和 Gossip
3. 分布式事务解决方案有2PC，3PC以及事务消息

---

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

## 第4章作业:Home4Devops
1. Code_Analysisgo在lint utils失败，不知原因

## 第5章作业: Home5基础设施自动化实践
1. [install](https://www.packer.io/downloads)
2. [Packer tutorial](https://learn.hashicorp.com/packer)
3. [使用packer构建自定义镜像](https://songjlg.github.io/2021/11/05/%E4%BD%BF%E7%94%A8packer%E6%9E%84%E5%BB%BA%E8%87%AA%E5%AE%9A%E4%B9%89%E9%95%9C%E5%83%8F/)
4. [使用Packer创建Ubuntu 18.04 Vagrant Box](https://www.igiftidea.com/article/12828727029.html)
5. 构建器，配置，预处理
6. [Ubuntu Hashes](https://help.ubuntu.com/community/UbuntuHashes)
7. packer build ubuntu1804.json
8. [SSH密钥验证](https://www.cnblogs.com/arnoLixi/p/10374208.html)
9. ToDo: 使用UserData安装ansible并配置ssh使用密钥登录 ???
```
cd "C:\Users\Su Cheng"
md .ssh
cd .ssh
# step 8

```

## 第6章作业: 仿真

## 第7章作业: 可视化

## 第8章作业: 服务发现和注册 