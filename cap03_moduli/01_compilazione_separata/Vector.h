//
// Created by enrico on 12/28/23.
//

#ifndef INC_01_COMPILAZIONE_SEPARATA_VECTOR_H
#define INC_01_COMPILAZIONE_SEPARATA_VECTOR_H
#include <iostream>

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
    void print() {
        std::cout << "[ ";
        for (int i=0; i<sz; ++i) {
            std::cout << elem[i] << " ";
        }
        std::cout << "]";
    }
private:
    double* elem;
    int sz;
};


#endif //INC_01_COMPILAZIONE_SEPARATA_VECTOR_H
