cmake_minimum_required(VERSION 3.22)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

include(FindGraphviz.cmake)

add_executable(edgerunner main.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h solvers/Solver.cpp solvers/Solver.h graph/Graph.cpp graph/Graph.h solvers/DFSSolver.cpp solvers/DFSSolver.h solvers/BFSSolver.cpp solvers/BFSSolver.h solvers/KruskalSolver.cpp solvers/KruskalSolver.h solvers/PrimSolver.cpp solvers/PrimSolver.h solvers/FloydWarshallSolver.cpp solvers/FloydWarshallSolver.h solvers/DijkstraSolver.cpp solvers/DijkstraSolver.h solvers/BellmanFordSolver.cpp solvers/BellmanFordSolver.h)
target_include_directories(edgerunner PUBLIC ${GRAPHVIZ_INCLUDE_DIRS})
target_link_libraries(edgerunner  PUBLIC ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY})