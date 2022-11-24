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