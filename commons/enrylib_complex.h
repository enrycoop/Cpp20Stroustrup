//
// Created by enrico on 1/9/24.
//

#ifndef COMMONS_ENRYLIB_COMPLEX_H
#define COMMONS_ENRYLIB_COMPLEX_H
namespace enrylib {

    class complex {
        double re, im;
    public:
        // Constructors
        complex(double r, double i) : re{r}, im{i} {}
        complex(double r) : re{r}, im{0} {}
        complex() : re{0}, im{0} {}
        complex(complex const &z) = default;     // costruttore di copia

        // Get and Set
        double real() const { return re; }
        void real(double d) { re=d; }
        double imag() const { return im; }
        void imag(double d) { im=d; }

        complex& operator+=(complex z)
        {
            re+=z.re;
            im+=z.im;
            return *this;
        }

        complex& operator-=(complex z)
        {
            re-=z.re;
            im-=z.im;
            return *this;
        }

        complex& operator*=(complex z)
        {
            double _re, _im;
            _re = re*z.re - im*z.im;
            _im = re*z.im + z.re*im;
            re = _re;
            im = _im;
            return *this;
        }

        complex& operator/=(complex z)
        {
            double _re, _im;
            double den = im*im + z.im*z.im;
            _re = (re*z.re + im*z.im)/den;
            _im = (re*z.im - z.re*im)/den;
            re = _re;
            im = _im;
            return *this;
        }

    };

    complex operator+(complex a, complex b) { return a+=b; }
    complex operator-(complex a, complex b) { return a-=b; }
    complex operator-(complex a) { return {-a.real(), -a.imag()}; } // meno unario
    complex operator*(complex a, complex b) { return a*=b; }
    complex operator/(complex a, complex b) { return a/=b; }

    bool operator==(complex a, complex b) { return a.real() == b.real() && a.imag() == b.imag(); }
    bool operator!=(complex a, complex b) { return !(a == b); }
}

#endif //COMMONS_ENRYLIB_COMPLEX_H
