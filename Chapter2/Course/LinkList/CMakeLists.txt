cmake_minimum_required(VERSION 3.22)
project (LinkList C)

set(CMAKE_C_STANDARD 99)

add_library(LinkList  library.c LinkList.cpp)
