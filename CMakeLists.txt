cmake_minimum_required(VERSION 2.8)
project(GMCL14)

add_compile_options(-std=c++14 -Wall -Wextra -fdiagnostics-color=auto -g)
include_directories(${PROJECT_SOURCE_DIR}/src)

enable_testing()

file(GLOB test_sources test/*.cpp)
foreach(path IN LISTS test_sources)
    get_filename_component(target ${path} NAME_WE)
    add_executable(${target} ${path})
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_link_libraries(${target} c++)
    endif()
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
    file(RELATIVE_PATH rpath ${CMAKE_SOURCE_DIR} ${path})
endforeach()

#set(SOURCE_FILES test/main.cpp)
#add_executable(GMCL14 ${SOURCE_FILES})
