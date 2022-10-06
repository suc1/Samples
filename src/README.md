# All ros examples

## Folder under src
1. CVBridgeTest

## Use https on github.com
[Use https on github](https://stackoverflow.com/questions/68775869/message-support-for-password-authentication-was-removed-please-use-a-personal)
```
# 1. Create Personal Access Token on GitHub
# 2. Linux setup
git config --global user.name "suc1"
git config --global user.email "ytsucheng@gmail.com"
git config -l

git config --global credential.helper cache

git clone https://<PersonalAccessToken>@github.com/<user>/<repo>.git
```

## Create ROS workspace & package
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
```
```
catkin_make
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3

catkin_create_pkg new_ros_package std_msgs rospy roscpp
```
## Checkout & Build
```
catkin_make -DCMAKE_BUILD_TYPE=Release
```

## 1. CVBridgeTest
```
source ~/Samples/devel/setup.bash

roslaunch realsense2_camera rs_camera.launch

rosrun CVBridgeTest testBridge.py
python              testBridge.py
```

## 2. beginner_tutorials
1. <<18. Reading messages from a bag file>>
```
rostopic echo /turtle1/cmd_vel | tee topic1.yaml
time rosbag play --immediate 2022-09-30-08-43-45.bag --topics /turtle1/cmd_vel

wget https://raw.githubusercontent.com/ElectricRCAircraftGuy/eRCaGuy_dotfiles/master/useful_scripts/ros_readbagfile.py

time ros_readbagfile.py 2022-09-30-08-43-45.bag /turtle1/cmd_vel

roswtf
```

## 3. 2dnav_pr2 & pr2_2dnav_gazebo & pr2_alpha
1. 没有使用原始包，只是为了练习 "3.Roslaunch tips for large projects"
2. 8.1.1 Practice-A. Separate packages for .launch and other config files
3. 8.1.2 Practice-B. Group many configs into a single package or fewer packages

## 4. node_example
1. <<5.Defining Custom Messages>>, <<ROSNodeTutorialPython>>

## 5. AMR/AbseilTest
1. [tutorial](https://abseil.io/docs/cpp/quickstart-cmake.html#linking-your-code-to-the-abseil-repository)
2. `git clone https://github.com/abseil/abseil-cpp.git`
3. [C++ Programming Guides](https://abseil.io/docs/cpp/guides/)
