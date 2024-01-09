cmake_minimum_required(VERSION 3.27)
project(commons C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(commons
        enrylib_complex.h
        main.cpp
        enrylib_vector.h)
