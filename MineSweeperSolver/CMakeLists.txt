# CMakeList.txt : CMake project for MineSweeperSolver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

file( GLOB LIB_SOURCES *.cpp )
file( GLOB LIB_HEADERS *.h )

add_library ( MineSweeperSolverLib ${LIB_SOURCES} ${LIB_HEADERS} )

