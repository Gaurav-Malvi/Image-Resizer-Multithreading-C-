cmake_minimum_required(VERSION 3.10)
project(Multithreading_Image_Resizer)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(result main.cpp)

target_link_libraries(result ${OpenCV_LIBS})

