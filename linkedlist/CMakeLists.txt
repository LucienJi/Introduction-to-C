cmake_minimum_required(VERSION 3.14)
project(linkedlist C)

set(CMAKE_C_STANDARD 99)

add_executable(linkedlist main.c Linked_List.h Linked_List_function.c)