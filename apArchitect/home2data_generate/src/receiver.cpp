#include "ros/ros.h"
#include "home2data_generate/message1.h"

void callback(const home2data_generate::message1ConstPtr& msg)
{
    ROS_INFO("Receive[%d]: [%d].[%d]", msg->count, msg->pubTime.sec, msg->pubTime.nsec);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Receiver");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("send_topic", 10, callback);
    ros::spin();

    return 0;
}