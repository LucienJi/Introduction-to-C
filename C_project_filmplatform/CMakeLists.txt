cmake_minimum_required(VERSION 3.14)
project(Project C)

set(CMAKE_C_STANDARD 99)

add_executable(Project main.c function_platform.c function_platform.h basic_information_platform.c)