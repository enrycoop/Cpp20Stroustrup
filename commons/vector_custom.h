//
// Created by enrico on 1/9/24.
//

#ifndef COMMONS_VECTOR_CUSTOM_H
#define COMMONS_VECTOR_CUSTOM_H

namespace stdlibfac {

    class Vector {
        double* elem;
        int sz;
    public:
        /////////////// CONSTRUCTORs /////////////////
        Vector(int s) : elem{new double[s]}, sz{s}
        {
            for (int i=0; i<s; ++i)
                elem[i] = 0;
        }
        Vector(std::initializer_list<double>);

        /////////////// DESTRUCTOR  /////////////////
        ~Vector() { delete[] elem; }

        /////////////// OPERATORs ///////////////////
        double& operator[](int i);
        int size() const { return sz; }
        void push_back(double);
        void print();
    };

    double& Vector::operator[](int i) {
        if (!(i>=0 && i<sz))
            throw std::out_of_range{"stdlibfac::Vector::operator[]"};
        return elem[i];
    }

    Vector::Vector(std::initializer_list<double> lst)
        :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
        {
            std::copy(lst.begin(), lst.end(), elem);
        }

    void Vector::push_back(double new_d) {
        // alloco nuovo vettore
        auto* _elem = new double[sz+1];
        // copio vecchi dati
        for (int i=0; i<sz; ++i)
            _elem[i] = elem[i];
        _elem[sz] = new_d;

        // libero vecchie risorse
        delete[] elem;

        // aggiorno risorse
        elem = _elem;
        sz++;
    }

    void Vector::print() {
        std::cout << "[ ";
        for (int i=0; i<sz; ++i) {
            std::cout << elem[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }
}

#endif //COMMONS_VECTOR_CUSTOM_H
