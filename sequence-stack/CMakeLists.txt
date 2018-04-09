cmake_minimum_required(VERSION 3.10)
project(sequence_stack C)

set(CMAKE_C_STANDARD 99)

add_executable(sequence_stack main.c sqstack.h sqstack.c)