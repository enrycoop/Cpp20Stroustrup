//
// Created by enrico on 1/9/24.
//

#ifndef COMMONS_ENRYLIB_VECTOR_H
#define COMMONS_ENRYLIB_VECTOR_H

namespace enrylib {
    class vector {
        double* elem;
        int sz;
    public:
        vector(int s) : elem{new double[s]}, sz{s} // costruttore: acquisisce risorse
        {
            for (int i=0; i<s; ++i) // inizializza elementi
                elem[i] = 0;
        }

        ~vector() { delete[] elem; }              // distruttore: rilascia risorse
        double& operator[](int i) const {
            if (!(i>=0 && i<sz))
                throw std::out_of_range{"enrylib::vector::operator[]"};
            return elem[i];
        }
        int size() const noexcept { return sz; }
    };
}

#endif //COMMONS_ENRYLIB_VECTOR_H
