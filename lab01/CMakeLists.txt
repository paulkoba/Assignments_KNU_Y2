cmake_minimum_required(VERSION 3.17)
project(lab01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -O3 -lgtest ")

add_executable(lab01 main.cpp include/sparse_matrix.h tests/sparse_matrix_tests.h)