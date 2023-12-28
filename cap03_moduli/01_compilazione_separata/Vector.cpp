//
// Created by enrico on 12/28/23.
//
#import "Vector.h"


Vector::Vector(int s) : elem{new double[s]}, sz{s}
{

}

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() {
    return sz;
}

