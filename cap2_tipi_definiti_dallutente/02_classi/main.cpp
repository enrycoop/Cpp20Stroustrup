#include <iostream>

using namespace std;

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} { }
    double& operator[](int i) { return elem[i]; }
    int size() { return sz; }

private:
    double* elem;
    int sz;
};

int main() {
    const int s = 6;
    Vector v(s);

    for (int i=0; i!=s; ++i) {
        cin>>v[i];
    }

    double sum = 0;
    for (int i=0; i!=s; ++i) {
        sum+=v[i];
    }

    cout << sum;

    return 0;
}
