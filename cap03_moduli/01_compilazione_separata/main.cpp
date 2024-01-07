#include <iostream>
#include <cmath>
#include "Vector.h"

int main() {
    Vector v(5);

    for (int i=0; i!=v.size(); ++i)
        v[i] = i;

    double sum = 0;
    for (int i=0; i!=v.size(); ++i) {
        sum += std::sqrt(v[i]);
    }
    v.print();
    std::cout << sum;
    return 0;
}
