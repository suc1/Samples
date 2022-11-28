# rosjava

[rosjava_core](https://rosjava.github.io/rosjava_core/latest/index.html)

## [Install Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu)
1. `apt-cache search ros-kinetic`

## Install rosjava
1. [rosjava_build_tools](https://wiki.ros.org/rosjava_build_tools)
2. [rosjava_rosjava_build_tools](https://github.com/rosjava/rosjava_build_tools/tree/kinetic)
3. [Setting up a plain ROS Java](https://spyroskoukas.com/2020/05/15/how-to-setup-a-ros-java-system-in-windows/)
4. [ROSJAVA Tutorial ](https://youtu.be/lujgeInpejY)
```
sudo apt-get install ros-$ROS_DISTRO-rosjava-build-tools ros-$ROS_DISTRO-rosjava-bootstrap

catkin_create_rosjava_pkg
catkin_create_rosjava_project				#catkin_make
catkin_create_rosjava_library_project
catkin_create_rosjava_msg_project

catkin_create_android_pkg
catkin_create_android_project
catkin_create_android_library_project

export APP_HOME=~/Samples/src/ros_java_pkg/my_pub_sub_tutorial/build/install/my_pub_sub_tutorial/
cd $APP_HOME/bin				#Or use below APP_HOME
./my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Talker &
./my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Listener &
```
```
roscd ros_java_pkg
cd my_pub_sub_tutorial/			#No need set APP_HOME because APP_HOME use this default dir
../gradlew install

roscore &
./build/install/my_pub_sub_tutorial/bin/my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Talker &
./build/install/my_pub_sub_tutorial/bin/my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Listener

////remap
roscore &
./build/install/my_pub_sub_tutorial/bin/my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Talker chatter:=/foo &
./build/install/my_pub_sub_tutorial/bin/my_pub_sub_tutorial com.github.rosjava.ros_java_pkg.my_pub_sub_tutorial.Listener chatter:=/foo

```

## Run Tutorial in rosjava_core
```
cd ~/rosjava_core
cd rosjava_tutorial_pubsub
../gradlew tasks
../gradlew build
../gradlew installDist

roscore &
./build/install/rosjava_tutorial_pubsub/bin/rosjava_tutorial_pubsub org.ros.rosjava_tutorial_pubsub.Talker &
./build/install/rosjava_tutorial_pubsub/bin/rosjava_tutorial_pubsub org.ros.rosjava_tutorial_pubsub.Listener &
```

```
cd rosjava_tutorial_services
../gradlew installDist

./build/install/rosjava_tutorial_services/bin/rosjava_tutorial_services  org.ros.rosjava_tutorial_services.Server &
./build/install/rosjava_tutorial_services/bin/rosjava_tutorial_services  org.ros.rosjava_tutorial_services.Client &
```

```
cd rosjava_tutorial_right_hand_rule
../gradlew installDist

./build/install/rosjava_tutorial_right_hand_rule/bin/rosjava_tutorial_right_hand_rule org.ros.rosjava_tutorial_right_hand_rule.RightHandRule &
```

## 依赖rosjava开发
1. In `ROSJAVA_CORE``build.gradle`:
```
apply plugin: 'application'
mainClassName = 'org.ros.RosRun'
dependencies {
  compile project(':rosjava')
}
defaultTasks 'publish', 'installDist'
```
2. In other project, use `/opt/ros/kinetic/share/maven` or `~/Samples/devel/share/maven`:
```
apply plugin: 'application'
mainClassName = 'org.ros.RosRun'
dependencies {
  compile 'org.ros.rosjava_core:rosjava:[0.1,)'
}
```

## [Windows中运行ROS Java](https://github.com/SpyrosKou/Plain-ROS-Java-System-Example)
1. 不需要任何 ROS 安装, JDK 17, Gradle 7.5.1, Windows Power Shell
2. 
```
#DOS
echo %JAVA_HOME%

#PowerShell
echo $Env:JAVA_HOME

$env:DEBUG=1
echo $Env:DEBUG
```
```
git clone https://github.com/SpyrosKou/Plain-ROS-Java-System-Example.git
cd .\Plain-ROS-Java-System-Example\
.\gradlew installDist

# mainClassName = "eu.spyros.koukas.ros.examples.Main"
.\build\install\Plain-ROS-Java-System-Example\bin\Plain-ROS-Java-System-Example.bat
.\gradlew run
.\gradlew runWithExternalRos
```

## [在Android中使用ROS](http://community.bwbot.org/topic/627/%E5%9C%A8android%E4%B8%AD%E4%BD%BF%E7%94%A8ros)


## [Maven](https://maven.apache.org/)
1. make->Ant->Maven->Gradle
2. [Maven教程](https://zhuanlan.zhihu.com/p/97830644)
3. [Maven Tutorial - Crash Course: 26min](https://youtu.be/Xatr8AZLOsE)
4. [Maven Full Course - Learn Maven From Scratch In 2 Hours](https://youtu.be/p0LPfK_oNCM)

## [Creating a new Java package](https://rosjava.github.io/rosjava_core/latest/getting_started.html#creating-a-new-java-package)
1. AbstractNodeMain : NodeMain : NodeListener
2. rosjava_tutorial_pubsub package: Talker
    1. `connectedNode.executeCancellableLoop`异步循环发布消息`CancellableLoop`
	2. `std_msgs.String str = publisher.newMessage()`rosjava中的消息不能直接实例化
3. rosjava_tutorial_pubsub package: Listener. `MessageListener.onNewMessage()`
4. 执行节点
```
./gradlew install
rosjava/build/libs/rosjava-0.3.7.jar
```