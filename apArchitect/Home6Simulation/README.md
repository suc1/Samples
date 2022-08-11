# Homework6 仿真
假设我们的无人车有两个摄像头，一个摄像头负责检测小狗，另一个摄像头负责监测小猫，

我们的算法会在收到一个摄像头的小狗数据的时候统计另一个摄像头监测到了多少小猫，
并把小猫小狗的个数和记录下来，录制成了一个rosbag。

写一个确定性仿真调度器，自己实现ros Subscriber收取录制的摄像头信息。当rosbag
play的时候，调度器能够调度我们的算法，并保证计算结果和rosbag中记录的结果一样。

## Video: 34:32
1. 自动驾驶仿真是如何实现的: 17:00
2. 仿真场景的来源: 24:00
3. Homwork: 33:09

## Design
Message: ImageDog, ImageCat
系统状态: 小猫小狗的个数
计算过程: CountCat, CountDog

车载调度系统: CarSchedule
仿真调度系统: SimSchedule (在Simulation里面)
rosbag: Record, play

## Implement 为了简单实现:
1. 摄像头图象采用一个随机整数
2. 计算过程对摄像头图象去重，再统计去重后的个数
3. 部分实现ROS Topic，采用scribe/callback, 但是避开IPC/Socket, 改用直接函数调用
4. rosbag不单独做为一个进程，避开IPC(只使用文件CatDog.bag), 调度系统启动后rosbag自动运行Record/Play
5. .bag文件格式: TXT, 每个消息一行(类型，数据). For example:
    1. 0, 11	//CAT相机,  图象内容是11
    2. 1, 20	//DOG相机,  图象内容是20
    3. 2, 8    //CAT计数, 8个
    4. 3, 6    //DOG计数, 6个
6. 不考虑线程安全
7. CarSchedule.exe 录制CatDog.bag
8. Simulation.exe 播放CatDog.bag