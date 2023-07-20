cmake_minimum_required(VERSION 3.25)
project(cpsc256)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloWorldCPP HelloWorldCPP/main.cpp)
add_executable(Declarations Declarations/main.c)
add_executable(BasicLinkedList BasicLinkedList/main.cpp BasicLinkedList/IntNode.cpp)
add_executable(MultipleClasses MultipleClasses/main.cpp)
