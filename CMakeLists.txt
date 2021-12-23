cmake_minimum_required(VERSION 3.19.2)
project(Math-Logics)

set(CMAKE_CXX_STANDARD 14)

#add_executable(untitled main.cpp bdd.h bdd.lib)
add_subdirectory (external/buddy bdd)

add_executable(Math-Logics main.cpp)
target_include_directories(Math-Logics PRIVATE "${PROJECT_SOURCE_DIR}/external/buddy/src")
target_link_libraries(Math-Logics bdd)
