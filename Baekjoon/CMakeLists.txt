cmake_minimum_required(VERSION 3.8)
project(Baekjoon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        10819.cpp
        1107.cpp
        12100.cpp
        1342.cpp
        14502.cpp
        14503.cpp
        1473.cpp
        1526.cpp
        1697.cpp
        1759.cpp
        1963.cpp
        2251.cpp
        2251queue.cpp
        9095.cpp
        test.cpp)

add_executable(Baekjoon ${SOURCE_FILES})