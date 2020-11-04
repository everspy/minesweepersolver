# CMakeList.txt

cmake_minimum_required (VERSION 3.8)

add_executable (MineSweeperInterpreter "MineSweeperInterpreter.cpp" "MineSweeperInterpreter.h")

target_link_libraries (MineSweeperInterpreter PRIVATE MineSweeperGameLib)
target_link_libraries (MineSweeperInterpreter PRIVATE MineSweeperSolverLib)



