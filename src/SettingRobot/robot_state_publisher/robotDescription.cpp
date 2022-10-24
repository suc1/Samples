#include <robot_state_publisher/robot_state_publisher.h>

RobotStatePublisher(const KDL::Tree& tree);

// publish moving joints
void publishTransforms(const std::map<std::string, double>& joint_positions,
                         const ros::Time& time);

// publish fixed joints
void publishFixedTransforms();

//It is okay if the map does not contain all the joint names
//It is also okay if the map contains some joints names that are not part of the kinematic model
