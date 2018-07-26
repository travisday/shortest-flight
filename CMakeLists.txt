cmake_minimum_required(VERSION 3.9)
project(flights)

set(CMAKE_CXX_STANDARD 11)

add_executable(flights main.cpp dijkstra.cpp dijkstra.h diredge.cpp diredge.h graph.cpp graph.h)