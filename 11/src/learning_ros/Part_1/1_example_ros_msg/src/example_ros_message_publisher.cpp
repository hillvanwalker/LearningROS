#include <ros/ros.h>
#include <example_ros_msg/ExampleMessage.h>
#include <math.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "example_ros_message_publisher");
    ros::NodeHandle n;
    ros::Publisher my_publisher_object = n.advertise<example_ros_msg::ExampleMessage>("example_topic", 1);
    example_ros_msg::ExampleMessage  my_new_message;
    ros::Rate naptime(1.0);
    my_new_message.header.stamp = ros::Time::now(); //set the time stamp in the header;
    my_new_message.header.seq=0; 
    my_new_message.header.frame_id = "base_frame";
    my_new_message.demo_int= 1;
    my_new_message.demo_double=100.0;
    double sqrt_arg;
    while (ros::ok()) {
        my_new_message.header.seq++;                     //increment the sequence counter
        my_new_message.header.stamp = ros::Time::now();  //update the time stamp
        my_new_message.demo_int*=2.0;                    //double the integer in this field
        sqrt_arg = my_new_message.demo_double;
        my_new_message.demo_double = sqrt(sqrt_arg);
        my_publisher_object.publish(my_new_message); 
        naptime.sleep(); 
    }
}

