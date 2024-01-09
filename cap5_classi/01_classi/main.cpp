#include <iostream>
#include "complex.h"

void f(enrylib::complex z) {
    using enrylib::complex;
    complex a {2.3};
    complex b {1/a};
    complex c {a+z*complex{1, 2.3}};
    if (c != b)
        c = -(b/a)+2 * b;
}


int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
