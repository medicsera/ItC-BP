cmake_minimum_required(VERSION 3.27)
project(ItC-BP)

set(CMAKE_C_STANDARD 23)

add_executable(lab1.main lab_num1/main.cpp lab_num1/matrix.cpp)
add_executable(lab2.firstExample lab_num2/FirstExample.cpp)
add_executable(lab2.secondExample lab_num2/SecondExample.cpp)
add_executable(lab2.thirdExample lab_num2/ThirdExample.cpp)
add_executable(lab3.main lab_num3/main.cpp lab_num3/QueryInterface.cpp)
add_executable(lab4.main lab_num4/main.cpp lab_num4/QueryInterface2.cpp)
add_executable(lab5.main lab_num5/main.cpp lab_num5/Interface.cpp)

set(SOURCES_COMMON
        lab_num6/src/GUIDs.cpp
        lab_num6/src/create.cpp
)

add_library(cmpnt1 SHARED lab_num6/src/cmpnt1.cpp ${SOURCES_COMMON})
add_executable(client1 lab_num6/src/client1.cpp ${SOURCES_COMMON})
target_link_libraries(client1 cmpnt1)

add_library(cmpnt2 SHARED lab_num6/src/cmpnt2.cpp ${SOURCES_COMMON})
add_executable(client2 lab_num6/src/client2.cpp ${SOURCES_COMMON})
target_link_libraries(client2 cmpnt2)

add_library(cmpnt3 SHARED lab_num6/src/cmpnt3.cpp ${SOURCES_COMMON})
add_executable(client3 lab_num6/src/client3.cpp ${SOURCES_COMMON})
target_link_libraries(client3 cmpnt3)
