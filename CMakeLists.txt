cmake_minimum_required(VERSION 3.22)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphsLyn mainLyn.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h solvers/Solver.cpp solvers/Solver.h graph/Graph.cpp graph/Graph.h solvers/DFSSolver.cpp solvers/DFSSolver.h)
add_executable(graphsLuc mainLuc.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h solvers/Solver.cpp solvers/Solver.h graph/Graph.cpp graph/Graph.h solvers/DijkstraSolver.cpp solvers/DijkstraSolver.h solvers/BellmanFordSolver.cpp solvers/BellmanFordSolver.h)