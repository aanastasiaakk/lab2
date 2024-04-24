cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        Singlylinkedlist.cpp
        Singlylinkedlist.h
        Doublelinkedlist.cpp
        Doublelinkedlist.h)
