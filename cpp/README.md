# C/C++

## 直接使用C callback弱点是什么
FunctionPointer:
重大疑问: C++ std::function没法比较callback函数指针是否相等，但是C的函数指针是可以的。Why?????? 因为模板？

## C++ 类设计和实现的十大最佳实践
1. [C++ 类设计和实现的十大最佳实践](https://mp.weixin.qq.com/s/pGj73TFpxCyUkEch_kbvKg)
2. [CppDepend](http://www.cppdepend.com)
3. [CQLinq](https://www.cppdepend.com/cqlinq)

## 聊一聊分布式锁的设计模型
1. [分布式锁](https://mp.weixin.qq.com/s/uA26VVmYMTfs-dWcLOY04w)
2. 性质: a）均匀分布 b）意外退出后再调度的均衡性 c）新的节点加入再平衡
3. 原则: a）绝对互斥 b）最终可用 c）服务容错
4. 特征: 抢锁效率，锁的均衡性，锁的精度，锁的可重入
5. DLM（Distributed Lock Manager）: 管控平面，负责容错、成员变更、角色调整; 数据平面，负责定序与持久化
