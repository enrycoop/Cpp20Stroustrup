//
// Created by enrico on 1/9/24.
//
#include <iostream>
#include "enrylib_vector.h"
#include "enrylib_complex.h"



int main() {
    enrylib::vector v(0);
    enrylib::complex c{1,2};

    v.print();

    for (int i=0; i<10; ++i) {
        v.push_back(i);

        v.print();
    }

}