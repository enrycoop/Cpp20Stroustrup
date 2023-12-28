#include <iostream>
#include <cmath>
import Vector;


double sqrt_sum(Vector& v) {
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += std::sqrt(v[i]);
    return sum;
}

int main() {



    return 0;
}
