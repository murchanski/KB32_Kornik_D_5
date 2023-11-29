cmake_minimum_required(VERSION 3.26)
project(Fourth_task C)

set(CMAKE_C_STANDARD 11)

add_executable(Fourth_task main.c
        child_process.c
        child_process.h)
