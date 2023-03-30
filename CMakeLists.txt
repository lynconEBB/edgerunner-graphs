cmake_minimum_required(VERSION 3.22)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphsLyn mainLyn.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h executors/Executor.cpp executors/Executor.h graph/Graph.cpp graph/Graph.h executors/DFSExecutor.cpp executors/DFSExecutor.h)
add_executable(graphsLuc mainLuc.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h executors/Executor.cpp executors/Executor.h graph/Graph.cpp graph/Graph.h)