// rosrun example_ros_class example_ros_class
// rostopic echo exampleMinimalPubTopic
// rostopic pub -r 4 exampleMinimalSubTopic std_msgs/Float32 2.0
// rosservice call exampleMinimalService 1

#include <creating_a_ros_library/example_ros_class.h>

// put all dirty work of initializations here
// 传递 nodehandle pointer 到这，用于 build subscribers, etc
ExampleRosClass::ExampleRosClass(ros::NodeHandle* nodehandle):nh_(*nodehandle){ // constructor
    ROS_INFO("in class constructor of ExampleRosClass");
    initializeSubscribers();
    initializePublishers();
    initializeServices();
    //initialize variables here, as needed
    val_to_remember_=0.0;
}

void ExampleRosClass::initializeSubscribers(){
    ROS_INFO("Initializing Subscribers");
    // &ExampleRosClass::subscriberCallback 是 pointer，指向成员函数
    // "this" 指针用于 refer to the current instance of ExampleRosClass
    minimal_subscriber_ = nh_.subscribe("example_class_input_topic", 1, &ExampleRosClass::subscriberCallback,this);  
    // add more subscribers here, as needed
}

void ExampleRosClass::initializeServices(){
    ROS_INFO("Initializing Services");
    minimal_service_ = nh_.advertiseService("example_minimal_service", &ExampleRosClass::serviceCallback, this);  
    // add more services here, as needed
}

void ExampleRosClass::initializePublishers(){
    ROS_INFO("Initializing Publishers");
    minimal_publisher_ = nh_.advertise<std_msgs::Float32>("example_class_output_topic", 1, true); 
    // add more publishers, as needed
    // 如果需要在 "main()"作用域下使用此函数，可将 minimal_publisher_ 作为 public function
}

void ExampleRosClass::subscriberCallback(const std_msgs::Float32& message_holder) {
    // real work is done in this callback function
    // 每当有 new message发布时都将进入此函数
    val_from_subscriber_ = message_holder.data; // 将数据复制到成员变量, 这样所有 member funcs都能access it
    ROS_INFO("myCallback activated: received value %f",val_from_subscriber_);
    std_msgs::Float32 output_msg;
    val_to_remember_ += val_from_subscriber_;
    output_msg.data= val_to_remember_;
    minimal_publisher_.publish(output_msg); //output
}

bool ExampleRosClass::serviceCallback(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response) {
    ROS_INFO("service callback activated");
    response.success = true; // boring, but valid response info
    response.message = "here is a response string";
    return true;
}