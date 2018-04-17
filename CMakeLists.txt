cmake_minimum_required(VERSION 3.8)
project(Algorithms)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Sort.c Sort.h SeqList.c SeqList.h LinkedList.c LinkedList.h CircleList.c CircleList.h)
add_executable(Algorithms ${SOURCE_FILES})