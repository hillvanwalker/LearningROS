// include this file in "example_ros_class.cpp"
#ifndef EXAMPLE_ROS_CLASS_H_
#define EXAMPLE_ROS_CLASS_H_

#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <ros/ros.h>

#include <std_msgs/Bool.h> 
#include <std_msgs/Float32.h>
#include <std_srvs/Trigger.h>

// define a class, including a constructor, member variables and member functions
class ExampleRosClass{
public:
    ExampleRosClass(ros::NodeHandle* nodehandle);
private:
    ros::NodeHandle nh_;
    ros::Subscriber minimal_subscriber_; 
    ros::ServiceServer minimal_service_;
    ros::Publisher  minimal_publisher_;
    double val_from_subscriber_; 
    double val_to_remember_;
    void initializeSubscribers(); 
    void initializePublishers();
    void initializeServices();
    void subscriberCallback(const std_msgs::Float32& message_holder);
    bool serviceCallback(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response);
};

#endif
