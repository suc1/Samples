# All ros examples

# Folder under src
1. CVBridgeTest

# Use https on github.com
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

# Create ROS workspace & package
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
```
```
catkin_make
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3

catkin_create_pkg new_ros_package std_msgs rospy roscpp
```
# Checkout & Build
```
catkin_make -DCMAKE_BUILD_TYPE=Release
```

# 1. CVBridgeTest
```
source ~/Samples/devel/setup.bash

roslaunch realsense2_camera rs_camera.launch

rosrun CVBridgeTest testBridge.py
python              testBridge.py
```
