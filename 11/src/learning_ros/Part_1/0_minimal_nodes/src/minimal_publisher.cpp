#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_publisher"); // name of this node
    ros::NodeHandle n;
    ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("topic1", 1); //name of the topic, buffer size of 1
    std_msgs::Float64 input_float;
    input_float.data = 0.0;
    // do work here in infinite loop, but terminate if detect ROS has faulted
    while (ros::ok()) {
        // loop 中没有 sleep timer, 因此极其消耗 CPU time
        input_float.data = input_float.data + 0.001;
        my_publisher_object.publish(input_float);
    }
}

