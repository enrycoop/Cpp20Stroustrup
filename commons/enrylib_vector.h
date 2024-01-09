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
        /////////////// CONSTRUCTORs /////////////////
        vector(int s) : elem{new double[s]}, sz{s} // costruttore: acquisisce risorse
        {
            for (int i=0; i<s; ++i) // inizializza elementi
                elem[i] = 0;
        }
        vector(std::initializer_list<double>);    // inizializza con una lista di double

        /////////////// DESTRUCTOR  /////////////////
        ~vector() { delete[] elem; }              // distruttore: rilascia risorse

        /////////////// OPERATORs ///////////////////
        double& operator[](int i);
        int size() const noexcept { return sz; }
        void push_back(double);
    };

    double& vector::operator[](int i) {
        if (!(i>=0 && i<sz))
            throw std::out_of_range{"enrylib::vector::operator[]"};
        return elem[i];
    }

    vector::vector(std::initializer_list<double> lst)
        :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
        {
            std::copy(lst.begin(), lst.end(), elem);
        }

    void vector::push_back(double) {

    }
}

#endif //COMMONS_ENRYLIB_VECTOR_H
