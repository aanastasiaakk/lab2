cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        singlylinkedlist.h
        doublylinkedlist.h
        Queue.h
        Stack.h
        CircularQueue.h
)
