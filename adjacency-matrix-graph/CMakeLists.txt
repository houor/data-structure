cmake_minimum_required(VERSION 3.10)
project(adjacency_matrix_graph C)

set(CMAKE_C_STANDARD 99)

add_executable(adjacency_matrix_graph main.c adjacencymatrixgraph.h adjacencymatrixgraph.c ../linked-queue/linkedqueue.h ../linked-queue/linkedqueue.c)