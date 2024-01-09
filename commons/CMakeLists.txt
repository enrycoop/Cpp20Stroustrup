cmake_minimum_required(VERSION 3.27)
project(commons)

set(CMAKE_CXX_STANDARD 20)

add_executable(commons
        enrylib_complex.h
        main.cpp
        enrylib_vector.h)
