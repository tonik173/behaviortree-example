cmake_minimum_required(VERSION 3.12)
project(simple_machine)

include_directories($ENV{HOME}/BehaviorTree.CPP/include)
link_directories($ENV{HOME}/build)

add_executable(${PROJECT_NAME} 
    "wire-loader.cpp" 
    "wire-drawer.cpp"     
    "wire-cutter.cpp" 
    "wire-stripper.cpp" 
    "machine.cpp"
    "main.cpp")

target_link_libraries(${PROJECT_NAME} behaviortree_cpp)

