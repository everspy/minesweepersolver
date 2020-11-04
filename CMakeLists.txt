# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("MineSweeperSolver")

set(SRC_DIR "src/")
set(CMAKE_CXX_FLAGS "-g -Wall")

# Include sub-projects.
add_subdirectory ("${SRC_DIR}MineSweeperInterpreter")
add_subdirectory ("${SRC_DIR}MineSweeperSolver")
add_subdirectory ("${SRC_DIR}MineSweeperGame")



