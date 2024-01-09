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
        vector(int s) : elem{new double[s]}, sz{s}
        {
            for (int i=0; i<s; ++i)
                elem[i] = 0;
        }
        vector(std::initializer_list<double>);

        /////////////// DESTRUCTOR  /////////////////
        ~vector() { delete[] elem; }

        /////////////// OPERATORs ///////////////////
        double& operator[](int i);
        int size() const { return sz; }
        void push_back(double);
        void print();
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

    void vector::push_back(double new_d) {
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

    void vector::print() {
        std::cout << "[ ";
        for (int i=0; i<sz; ++i) {
            std::cout << elem[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }
}

#endif //COMMONS_ENRYLIB_VECTOR_H
