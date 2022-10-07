# All ros packages
All ros packages for AMR. Gitea is a mirror of GitHub.
`checkoutSubmodule.sh`
`catkin_create_pkg angles_test std_msgs rospy roscpp angles`

## angles: 角度库
1. [Gitea](http://192.168.3.82:3000/ROS1/angles.git)
2. [GitHub](https://github.com/ros/angles)
3. [ROS](https://wiki.ros.org/angles)
4. [API](https://docs.ros.org/en/api/angles/html/)
5. `git checkout tags/1.9.11`	#1.9.11 (2017-04-14)

## costmap_prohibition_layer
1. [Gitea](http://192.168.3.82:3000/ROS1/costmap_prohibition_layer.git)
2. [GitHub](https://github.com/rst-tu-dortmund/costmap_prohibition_layer)
3. [ROS](http://wiki.ros.org/costmap_prohibition_layer)
4. [Tutorial](http://wiki.ros.org/costmap_2d/Tutorials/Configuring%20Layered%20Costmaps)
5. `git checkout tags/0.0.5`		#0.0.5 (2017-01-25)

## linux-wifi-hotspot
1. [Gitea](http://192.168.3.82:3000/ROS1/linux-wifi-hotspot.git)
2. [GitHub](https://github.com/lakinduakash/linux-wifi-hotspot)

## navigation
1. [Gitea](http://192.168.3.82:3000/ROS1/navigation.git)
2. [GitHub](https://github.com/ros-planning/navigation)
3. [ROS](http://wiki.ros.org/navigation)
4. [Tutorial-melodic](http://wiki.ros.org/navigation_tutorials)
5. [navigation/Tutorials](http://wiki.ros.org/navigation/Tutorials)
6. `git checkout tags/1.16.6`	#1.16.6 (2020-03-18) V1.0 0d0cc7035

## navigation_msgs
1. [Gitea](http://192.168.3.82/ROS1/navigation_msgs)
2. [GitHub](http://github.com/ros-planning/navigation_msgs)
3. `git checkout tags/1.14.1`	#1.14.1 (2020-11-02) 793d06ff51/ros1

## rplidar_ros
1. [Gitea](http://192.168.3.82:3000/ROS1/rplidar_ros.git)
2. [GitHub](https://github.com/Slamtec/rplidar_ros)
3. [ROS](http://wiki.ros.org/rplidar)
4. [Tutorial](https://github.com/robopeak/rplidar_ros/wiki)
5. `git checkout AGV` OR `git checkout 3c770ba388`	#1.12.0 (2019-12-30)

## abseil: Google C++ 扩充库
1. [Gitea]()
2. [GitHub](https://github.com/abseil/abseil-cpp.git)
3. [ROS](http://wiki.ros.org/abseil_cpp)
4. [Tutorial](https://abseil.io/docs/cpp/quickstart)
5. `git checkout lts_2020_02_25`

## SLAM/cartographer
1. [Gitea](http://192.168.3.82:3000/ROS1/cartographer.git)
2. [GitHub](https://github.com/googlecartographer/cartographer)
3. [ROS](http://wiki.ros.org/cartographer)
4. [Tutorial](https://google-cartographer-ros.readthedocs.io/en/latest/)
5. `git checkout bcd5486025df`	#(2019-5-8) Fix missing bazel dependency (#1576)

## SLAM/cartographer_ros
1. [Gitea](http://192.168.3.82:3000/ROS1/cartographer_ros.git)
2. [GitHub](https://github.com/cartographer-project/cartographer_ros)
3. `git checkout 1de03b3d32b9`	#(2019-8-27)

## SLAM/ceres-solver: 非线性最小二乘优化, 一般无约束优化问题
1. [Gitea](http://192.168.3.82:3000/ROS1/ceres-solver.git)
2. [GitHub](https://github.com/ceres-solver/ceres-solver)
3. [Tutorial](http://ceres-solver.org/tutorial.html)
4. `git checkout tags/1.14.0`	#1.14.0 (2018-3-31)
5. `g++ -I/home/cheapx/robot/devel_isolated/ceres-solver/include -I/usr/include/eigen3 helloWorld.cpp -L/home/cheapx/robot/devel_isolated/ceres-solver/lib -lceres -lgflags -lglog -llapack -lcamd -lamd -lccolamd -lcolamd -lcholmod -lcxsparse -fopenmp -lpthread -lgomp -lm -lblas`
6. [eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html)
7. [eigen](https://gitlab.com/libeigen/eigen/-/tree/master)
8. eigen 线性代数库：矩阵、向量、数值求解器

