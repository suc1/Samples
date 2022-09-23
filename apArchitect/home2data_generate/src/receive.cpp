#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Receive: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Receiver");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("send_topic", 10, callback);
    ros::spin();

    return 0;
}