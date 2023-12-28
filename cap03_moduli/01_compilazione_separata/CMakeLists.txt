cmake_minimum_required(VERSION 3.25)
project(01_compilazione_separata)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_compilazione_separata main.cpp
        Vector.h
        Vector.cpp)
