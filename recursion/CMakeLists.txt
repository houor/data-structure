cmake_minimum_required(VERSION 3.10)
project(recursion C)

set(CMAKE_C_STANDARD 99)

add_executable(recursion main.c recursion.h recursion.c)