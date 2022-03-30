cmake_minimum_required(VERSION 3.18)

project(algorithms VERSION 1.0.0 DESCRIPTION "The collection of C++ algorithms")

include(cmake/ProjectOptions.cmake)
include(cmake/ProjectConfigs.cmake)
include(cmake/ProjectResources.cmake)

add_subdirectory(src/union-find)
add_subdirectory(src/string)
add_subdirectory(src/sort)
add_subdirectory(src/tools)
add_subdirectory(src/tree)
add_subdirectory(src/geometry)
add_subdirectory(src/hash)
add_subdirectory(src/graph)
add_subdirectory(src/compression)
add_subdirectory(src/crypto)
add_subdirectory(src/container)