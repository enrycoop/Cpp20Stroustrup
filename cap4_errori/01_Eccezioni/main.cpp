/*
 * ECCEZIONI
 * Considerate ancora l'esempio di Vector. Che cosa si dovrebbe fare quando si tenta di accedere a un elemento che esula
 * dall'intervallo del vettore?
 *  - Chi ha scritto Vector non sa che cosa l'utente voglia che accada in questo caso.
 *  - L'utente di Vector non è in grado di rilevare il problema in modo coerente.
 */

#include <iostream>


class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}
    double& operator[](int i);
    int size() { return sz; }
    void print() {
        std::cout << "[ ";
        for (int i=0; i<sz; ++i) {
            std::cout << elem[i] << " ";
        }
        std::cout << "]";
    }
private:
    double* elem;
    int sz;
};

double& Vector::operator[](int i)
// lancio di un'eccezione per avvisare che una precondizione non e' soddisfatta
{
    if (!(0<i && i<sz))
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

void compute1(Vector& v) {
    v[5];
    std::cout << "Compute1: OK\n";
}

void compute2(Vector& v) {
    v[1];
    std::cout << "Compute2: OK\n";
}

void compute3(Vector& v) {
    v[30];
    std::cout << "Compute3: OK\n";
}

void f(Vector& v) {
    try {
        compute1(v);
        compute2(v);
        compute3(v);
    } catch (const std::out_of_range& err) { // cattura dell'eccezione nel caso in cui qualcosa fallisca
        // gestione dell'eccezione per poter proseguire il programma
        std::cerr << err.what() << '\n';
    }
}

int main() {
    Vector v(6);
    f(v);
    return 0;
}
