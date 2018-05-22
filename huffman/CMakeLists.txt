cmake_minimum_required(VERSION 3.10)
project(huffman C)

set(CMAKE_C_STANDARD 99)

add_executable(huffman main.c huffman.h huffman.c)