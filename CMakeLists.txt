cmake_minimum_required(VERSION 3.27)
project(new_target)

set(CMAKE_CXX_STANDARD 23)

# Указываем, что это консольное приложение
add_executable(new_target lab_num1/matrix.cpp lab_num1/tests.cpp)