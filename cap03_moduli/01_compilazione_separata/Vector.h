//
// Created by enrico on 12/28/23.
//

#ifndef INC_01_COMPILAZIONE_SEPARATA_VECTOR_H
#define INC_01_COMPILAZIONE_SEPARATA_VECTOR_H


class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};


#endif //INC_01_COMPILAZIONE_SEPARATA_VECTOR_H
