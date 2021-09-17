#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_publisher2"); 
    ros::NodeHandle n;
    ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("topic1", 1);
    std_msgs::Float64 input_float;

   ros::Rate naptime(1.0); //create a ros object from the ros “Rate” class; 
   //set the sleep timer for 1Hz repetition rate
    input_float.data = 0.0;
    while (ros::ok()) {
        input_float.data = input_float.data + 0.001;
        my_publisher_object.publish(input_float);
        // sleep for the balance
        naptime.sleep(); 
    }
}

