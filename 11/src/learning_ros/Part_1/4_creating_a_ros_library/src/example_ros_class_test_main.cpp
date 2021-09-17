#include <creating_a_ros_library/example_ros_class.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "example_lib_test_main"); //node name
    ros::NodeHandle nh; // node handle，传递给 constructor
    ROS_INFO("main: instantiating an object of type ExampleRosClass");
    ExampleRosClass exampleRosClass(&nh);  // 实例化
    ROS_INFO("main: going into spin; let the callbacks do all the work");
    ros::spin();
    return 0;
}
