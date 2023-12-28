#include <iostream>
#include <cmath>
#include "Vector.h"

int main() {
    Vector v(5);

    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += std::sqrt(v[i]);
    std::cout << sum;
    return 0;
}
