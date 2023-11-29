cmake_minimum_required(VERSION 3.26)
project(First_task C)

set(CMAKE_C_STANDARD 11)

add_executable(First_task main.c
        command_executor.h
        command_executor.c)
