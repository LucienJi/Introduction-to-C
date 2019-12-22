cmake_minimum_required(VERSION 3.14)
project(stack C)

set(CMAKE_C_STANDARD 99)

add_executable(stack main.c stack_linkedlist.c stack_linkedlist.h stack_array.c stack_array.h)