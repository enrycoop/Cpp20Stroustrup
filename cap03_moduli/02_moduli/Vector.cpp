//
// Created by enrico on 12/28/23.
//
export module Vector; // definizione del modulo chiamato "Vector"

export class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};

Vector::Vector(int s) : elem{new double[s]}, sz{s}
{

}

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() {
    return sz;
}

export bool operator==(const Vector& v1, const Vector& v2)
{
    if (v1.size()!=v2.size()) {
        return false;
    }
    for (int i=0; i!=v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
}
