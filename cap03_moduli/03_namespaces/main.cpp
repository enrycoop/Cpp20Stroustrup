#include <iostream>
#include <cmath>


namespace MyCode {
    class complex {
        double x,y;
    public:
        complex(double x, double y): x{x}, y{y} {}
        double real() { return x; }
        double imag() { return y; }
        // ..
    };
    complex sqrt(complex a) {
        using std::sqrt;
        double x = sqrt(a.real());
        double y = sqrt(a.imag());
        complex ret{x,y};
        return ret;
    }

    int main();
}

int MyCode::main()
{
    using namespace std;
    complex z {1,2};
    auto z2 = sqrt(z);
    cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    return 0;
}

int main() {

    return MyCode::main();
}
