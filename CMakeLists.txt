cmake_minimum_required(VERSION 3.22)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

include(FindGraphviz.cmake)

add_executable(graphsLuc mainLuc.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h solvers/Solver.cpp solvers/Solver.h graph/Graph.cpp graph/Graph.h solvers/DijkstraSolver.cpp solvers/DijkstraSolver.h solvers/BellmanFordSolver.cpp solvers/BellmanFordSolver.h solvers/FloydWarshallSolver.cpp solvers/FloydWarshallSolver.h)

add_executable(graphsLyn mainLyn.cpp graph/GraphGenerator.cpp graph/GraphGenerator.h App.cpp App.h solvers/Solver.cpp solvers/Solver.h graph/Graph.cpp graph/Graph.h solvers/DFSSolver.cpp solvers/DFSSolver.h solvers/BFSSolver.cpp solvers/BFSSolver.h solvers/KruskalSolver.cpp solvers/KruskalSolver.h solvers/PrimSolver.cpp solvers/PrimSolver.h)
target_include_directories(graphsLyn PUBLIC ${GRAPHVIZ_INCLUDE_DIRS})
target_link_libraries(graphsLyn PUBLIC ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY})