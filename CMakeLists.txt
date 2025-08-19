cmake_minimum_required(VERSION 4.0)
project(todoListManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(todoListManager main.cpp
        TodoListManager.h
        TodoListManager.cpp
        input.cpp
        input.h)
