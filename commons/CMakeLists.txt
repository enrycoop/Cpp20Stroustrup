cmake_minimum_required(VERSION 3.27)
project(commons)

set(CMAKE_CXX_STANDARD 20)

add_executable(commons
        complex_custom.h
        main.cpp
        vector_custom.h
        std_lib_facilities.h
        container_custom.h)
