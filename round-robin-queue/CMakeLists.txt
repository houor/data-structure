cmake_minimum_required(VERSION 3.10)
project(round_robin_queue C)

set(CMAKE_C_STANDARD 99)

add_executable(round_robin_queue main.c rrqueue.h rrqueue.c)