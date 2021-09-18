//example_ros_class.cpp:
//illustrates how to use classes to make ROS nodes
#include "example_ros_class.h"

ExampleRosClass::ExampleRosClass(ros::NodeHandle* nodehandle):nh_(*nodehandle){ // constructor
    ROS_INFO("in class constructor of ExampleRosClass");
    initializeSubscribers(); 
    initializePublishers();
    initializeServices();
    val_to_remember_=0.0; 
}

void ExampleRosClass::initializeSubscribers(){
    ROS_INFO("Initializing Subscribers");
    // "this" refer to the current instance of ExampleRosClass
    minimal_subscriber_ = nh_.subscribe("example_class_input_topic", 1, &ExampleRosClass::subscriberCallback,this);  
}

void ExampleRosClass::initializeServices(){
    ROS_INFO("Initializing Services");
    minimal_service_ = nh_.advertiseService("example_minimal_service",
                                                   &ExampleRosClass::serviceCallback,
                                                   this);  
}

void ExampleRosClass::initializePublishers(){
    ROS_INFO("Initializing Publishers");
    minimal_publisher_ = nh_.advertise<std_msgs::Float32>("example_class_output_topic", 1, true); 
}

void ExampleRosClass::subscriberCallback(const std_msgs::Float32& message_holder) {
    val_from_subscriber_ = message_holder.data; 
    ROS_INFO("myCallback activated: received value %f",val_from_subscriber_);
    std_msgs::Float32 output_msg;
    val_to_remember_ += val_from_subscriber_; 
    output_msg.data= val_to_remember_;
    minimal_publisher_.publish(output_msg);
}

bool ExampleRosClass::serviceCallback(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response) {
    ROS_INFO("service callback activated");
    response.success = true; // boring, but valid response info
    response.message = "here is a response string";
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "exampleRosClass");
    ros::NodeHandle nh; 
    ROS_INFO("main: instantiating an object of type ExampleRosClass");
    ExampleRosClass exampleRosClass(&nh); 
    ROS_INFO("main: going into spin; let the callbacks do all the work");
    ros::spin();
    return 0;
}

