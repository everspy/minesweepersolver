# CMakeList.txt : CMake project for MineSweeperGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

file( GLOB LIB_SOURCES *.cpp )
file( GLOB LIB_HEADERS *.h )
add_library( MineSweeperGameLib ${LIB_SOURCES} ${LIB_HEADERS} )
#add_library (MineSweeperGame "MineSweeperGame.cpp" "MineSweeperGame.h")
