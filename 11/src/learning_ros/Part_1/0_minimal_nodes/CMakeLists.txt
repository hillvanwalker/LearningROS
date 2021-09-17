cmake_minimum_required(VERSION 2.8.3)
project(minimal_nodes)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES minimal_nodesmal_publish
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(minimal_publisher src/minimal_publisher.cpp)
add_executable(sleepy_minimal_publisher src/sleepy_minimal_publisher.cpp)
add_executable(minimal_subscriber src/minimal_subscriber.cpp)
add_executable(minimal_simulator src/minimal_simulator.cpp)
add_executable(minimal_controller src/minimal_controller.cpp)

target_link_libraries(minimal_publisher  ${catkin_LIBRARIES} )
target_link_libraries(sleepy_minimal_publisher  ${catkin_LIBRARIES} )
target_link_libraries(minimal_subscriber  ${catkin_LIBRARIES} )
target_link_libraries(minimal_simulator  ${catkin_LIBRARIES} )
target_link_libraries(minimal_controller  ${catkin_LIBRARIES} )