cmake_minimum_required(VERSION 3.3)
project(GMCL14)

add_compile_options(-std=c++14 -Wall -Wextra -fdiagnostics-color=auto -g)
include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp gmcl14/containers/dyn2d.hpp)
add_executable(GMCL14 ${SOURCE_FILES})