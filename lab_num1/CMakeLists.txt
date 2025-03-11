cmake_minimum_required(VERSION 3.27)
project(ItC-BP)

set(CMAKE_CXX_STANDARD 23)

add_executable(ItC-BP main.cpp
        matrix_oop.h
        matrix.cpp)
