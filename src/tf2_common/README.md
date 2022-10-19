# tf2 common Tutorials
[Tutorials](http://wiki.ros.org/tf2)
[github](https://github.com/jsk-ros-pkg/geometry2_python3)

## tf2 command
1. `rosrun rqt_tf_tree rqt_tf_tree`
2. `rosrun tf2_tools view_frames.py`, `evince frames.pdf`
3. `rosrun tf view_frames`, `evince frames.pdf`
4. `roswtf`
5. `rosrun tf tf_monitor`
6. `rosrun tf tf_monitor /base_footprint /odom`
7. `rosrun tf tf_echo [reference_frame] [target_frame]`
8. `rostopic echo /tf_static`
9. static_transform_publisher  x  y  z  yaw  pitch  roll  frame_id  child_frame_id  period_in_ms
10. static_transform_publisher  x  y  z  qx   qy   qz  qw  frame_id  child_frame_id  period_in_ms
11. node pkg="tf" type="static_transform_publisher" name="link1_broadcaster" args="1 0 0 0 0 0 1 link1_parent link1 100"
12. tf2::tf2Vector4, tf2::Matrix3x3, tf2::Quaternion, tf2::Transform
13. BufferListener, BufferBroadcaster, BufferServer, BufferClient
14. rosrun rviz rviz -d `rospack find turtle_tf2`/rviz/turtle_rviz.rviz
15. [tf_keyboard_cal](https://github.com/davetcoleman/tf_keyboard_cal.git)
16. [design](http://wiki.ros.org/tf2/Design)