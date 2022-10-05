#include "ros/ros.h"

#include <angles/angles.h>
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "angles_test");
    ros::NodeHandle n;

    double rad = angles::from_degrees(180);
    std::cout << rad <<std::endl;

    ros::spin();
    return 0;
}