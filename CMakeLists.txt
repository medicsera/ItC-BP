cmake_minimum_required(VERSION 3.27)
project(ItC-BP)

set(CMAKE_C_STANDARD 23)

add_executable(lab1.main lab_num1/main.cpp lab_num1/matrix.cpp)
add_executable(lab2.firstExample lab_num2/FirstExample.cpp)
add_executable(lab2.secondExample lab_num2/SecondExample.cpp)
add_executable(lab2.thirdExample lab_num2/ThirdExample.cpp)
add_executable(lab3.main lab_num3/main.cpp lab_num3/QueryInterface.cpp)