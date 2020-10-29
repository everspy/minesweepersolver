# CMakeList.txt : CMake project for MineSweeperSolver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

add_executable (MineSweeperSolver "MineSweeperSolver.cpp" "MineSweeperSolver.h")

# TODO: Add tests and install targets if needed.

target_link_libraries (MineSweeperSolver PRIVATE MineSweeperGameLib)