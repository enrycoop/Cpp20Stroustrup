#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& v)
{
    int s = 0;
    for (const int i : v)
        s += i;
    return s;
}

void test (vector<int> v, vector<int>& rv)
/*
 * v verra copiato
 * rv verra linkato il riferimento quindi puo essere modificato
 */
{
    v[1] = 99;
    rv[2] = 66;
}

void print(int value, int base =10)
// base avra valore di default 10 se non verra inserito un valore
{
    //...
}

class Vector{
public:
    Vector(int s) : elem{new double [s]}, sz{s} {}
    double& operator[](int i) { return elem[i];}  // retituisce il riferimento all'i-esimo elemento

private:
    double* elem;
    int sz;
};

int main() {
    //vector fib = {1, 2, 3, 5, 8, 13, 21};
    //int x = sum(fib);
    //cout << x;
    //test(fib, fib);
    //cout << fib[1] << ' ' << fib[2] << '\n';

    return 0;
}
