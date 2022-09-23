#include "ros/ros.h"
#include "home2data_generate/message1.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sender");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<home2data_generate::message1>("send_topic", 10);
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        home2data_generate::message1 msg;
        msg.pubTime = ros::Time::now();
        msg.count = count;

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}