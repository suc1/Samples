# tf2 Tutorials
[Tutorials](http://wiki.ros.org/tf2/Tutorials)

## tf2 command
1. [1. Writing a tf2 static broadcaster](https://github.com/ros/geometry_tutorials/tree/indigo-devel/turtle_tf2)
2. [2. Writing a tf2 broadcaster](http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20broadcaster%20%28Python%29)
3. [3. Writing a tf2 listener](http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20listener%20%28Python%29)
4. rospy.ServiceProxy('spawn', turtlesim.srv.Spawn)创建进程和roslaunch区别
5. [4. Adding a frame]()
6. [5. Learning about tf2 and time]()
7. [6. Time travel with tf2]()
8. [PeekKey C++](https://github.com/ros/ros_tutorials/blob/noetic-devel/turtlesim/tutorials/teleop_turtle_key.cpp)

## tf2_ros::MessageFilter
```cpp
tf2_ros::Buffer 	   buffer_;
tf2_ros::TransformListener tf2_;		//tf2_(buffer_)

tf2_ros::MessageFilter<geometry_msgs::PointStamped> tf2_filter_;
tf2_filter_(point_sub_, buffer_, target_frame_, 10, 0)
{
    point_sub_.subscribe(n_, "turtle_point_stamped", 10);
    tf2_filter_.registerCallback( boost::bind(&PoseDrawer::msgCallback, this, _1) );
}

void msgCallback(const geometry_msgs::PointStampedConstPtr& point_ptr)
{
    geometry_msgs::PointStamped point_out;
    try
    {
      buffer_.transform(*point_ptr, point_out, target_frame_);

      ROS_INFO("point of turtle 3 in frame of turtle 1 Position(x:%f y:%f z:%f)\n",
             point_out.point.x,
             point_out.point.y,
             point_out.point.z);
    }
    catch (tf2::TransformException &ex)
    {
      ROS_WARN("Failure %s\n", ex.what()); //Print exception which was caught
    }
}
```
`rosrun learning_tf2 learning_tf2_node`