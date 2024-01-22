#include <iostream>
#include <complex>
#include <memory>
#include <vector>


int main() {
    //auto c = new std::complex(1,2);
    // senza una delete c non viene deallocata automaticamente, dando origine a memory leak

    // usare unique_ptr puo risolvere il problema in maniera semplice
    auto u = std::make_unique<std::complex<int>>(1,2);
    {
        using namespace std;

        vector<unique_ptr<complex<int>>> v;
        int i, j;
        while(cin >> i >> j)
            v.push_back(make_unique<complex<int>>(i,j));
    }

    return 0;
}
