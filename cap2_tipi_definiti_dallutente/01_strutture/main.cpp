#include <iostream>

using namespace std;

struct Vector {
    double* elem;     // puntatore agli elementi
    int sz;           // numero di elementi
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);

    for (int i=0; i!=s; ++i) {
        cin >> v.elem[i];
    }

    double sum = 0;
    for (int i=0; i!=s; ++i) {
        sum+=v.elem[i];
    }
    return sum;
}

void f(Vector v, Vector& rv, Vector* pv) {
    int i1 = v.sz;
    int i2 = rv.sz;
    int i3 = pv->sz;
}

int main() {

    cout << read_and_sum(5);
    
    return 0;
}
