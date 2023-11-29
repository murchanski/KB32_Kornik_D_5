cmake_minimum_required(VERSION 3.26)
project(Second_task C)

set(CMAKE_C_STANDARD 11)

add_executable(Second_task main.c
        signals.h
        signals.c)
