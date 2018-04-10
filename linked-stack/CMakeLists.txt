cmake_minimum_required(VERSION 3.10)
project(linked_stack C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_stack main.c linkedstack.h linkedstack.c)