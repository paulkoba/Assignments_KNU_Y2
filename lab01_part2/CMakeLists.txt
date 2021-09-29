cmake_minimum_required(VERSION 3.17)
project(lab01_part2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -O3 -lgtest ")

add_executable(lab01_part2 main.cpp solid_of_revolution.cpp solid_of_revolution.h tests/solid_of_revolution_tests.h expression_parser.h tests/expression_parser_tests.h)