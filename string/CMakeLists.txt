cmake_minimum_required(VERSION 3.10)
project(string C)

set(CMAKE_C_STANDARD 99)

add_executable(string main.c fixlengthstring.h fixlengthstring.c)