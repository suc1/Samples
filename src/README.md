# All ros example


# Folder under src

# Checkout & Build
```
catkin_make -DCMAKE_BUILD_TYPE=Release
```

# Run testBridge.py
```
source ~/Samples/devel/setup.bash

roslaunch realsense2_camera rs_camera.launch

rosrun CVBridgeTest testBridge.py
python              testBridge.py
```
