// 对头文件 always do this，这样只会 included if needed, 而不会 get included multiple times
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

// 定义类，包括 构造函数，成员变量与成员函数
class ExampleRosClass{
public:
    // main函数需要实例化 instantiate一个 ROS nodehandle，然后传递到此 constructor
    ExampleRosClass(ros::NodeHandle* nodehandle); 
    // 定义共有函数和共有变量, if desired
private:
    // 私有变量 只被成员函数访问
    ros::NodeHandle nh_; // 必须，用于 pass between "main" and constructor
    // 一些成员 用于支持 subscriber, service, and publisher
    ros::Subscriber minimal_subscriber_; // 在构造函数内初始化
    ros::ServiceServer minimal_service_;
    ros::Publisher  minimal_publisher_;
    double val_from_subscriber_; 
    double val_to_remember_;
    // member methods
    void initializeSubscribers();
    void initializePublishers();
    void initializeServices();
    void subscriberCallback(const std_msgs::Float32& message_holder);
    bool serviceCallback(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response);
};

#endif  // ALWAYS need one of these to match #ifndef
