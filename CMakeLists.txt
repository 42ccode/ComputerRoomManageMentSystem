cmake_minimum_required(VERSION 3.28)
project(ComputerRoom)

set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(ComputerRoom
        ComputerRoomYuYue.cpp
        student.cpp
        teacher.cpp
        manager.cpp
        computerRoom.h)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR})
