//
// Created by enrico on 1/9/24.
//
#include <iostream>
#include "enrylib_vector.h"
#include "enrylib_complex.h"



int main() {
    enrylib::vector v(10);
    enrylib::complex c{1,2};

    std::cout << "[ ";
    for (int i=0; i<v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << "]" << std::endl;
}