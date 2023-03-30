cmake_minimum_required(VERSION 3.22)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphs main.cpp GraphGenerator.cpp GraphGenerator.h)
