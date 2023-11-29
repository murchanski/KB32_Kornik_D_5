cmake_minimum_required(VERSION 3.26)
project(Third_task C)

set(CMAKE_C_STANDARD 11)

add_executable(Third_task main.c
        command_processor.c
        command_processor.h)
