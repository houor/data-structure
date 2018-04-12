cmake_minimum_required(VERSION 3.10)
project(linked_queue C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_queue main.c linkedqueue.h linkedqueue.c)