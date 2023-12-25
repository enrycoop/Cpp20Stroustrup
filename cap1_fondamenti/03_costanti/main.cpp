/*
 * C++ supporta due tipi di immutabilita':
 * - const:
 *          in linea di massima significa "prometto di non camiare questo valore". Il compilatore applica la promessa
 *          Il valore di una costante non puo' essere calcolato in fase di esecuzione.
 * - constexpr:
 *          in linea di massima significa "da valutare in fase di compilazione" usato per le prestazioni. Il valore puo'
 *          essere calcolato dal compilatore
 * In alcuni punti le espressioni costanti sono richieste dalle regole del linguaggio (per esempio nei limiti degli array,
 * nelle etichette case, negli argomenti valore dei template e nelle costanti dichiarate constexpr). In altri casi,
 * la valutazione all'atto della compilazione e' importante per le prestazioni.
 */

#include <cmath>
#include <iostream>
#include <vector>

double sum(const std::vector<double>& v) {        // sum non modifica il suo argomento
    double tot {0.0};
    for (double d : v)
        tot += d;
    return tot;
}

constexpr double square(double x) { return x*x; }

consteval double square2(double x) { return x*x; }

int main() {
    constexpr int dmv = 17;                       // dmv e' una costante con nome
    int var = 17;                                 // var non e' una costante
    const double sqv = std::sqrt(var);            // sqv e' una costante con nome, possibilmente calcolato
                                                  // in fase di esecuzione

    std::vector<double> v {1.2, 3.4, 4.5};        // v non e' una costante
    const double s1 = sum(v);                     // OK: da valutare in fase di esecuzione
    //constexpr double s2 = sum(v);               // Error: sum(v) non e' un espressione costante

    // per poter essere usata in un espressione costante, ovvero un espressione che sara valutata dal compilatore
    // una funzione deve essere definita constexpr o consteval.

    // constexpr double square(double x) { return x*x; }

    constexpr double max1 = 1.4 * square(17);   // OK: square(17) e' un espressione costante
    //constexpr double max2 = 1.4 * square(var);  // errore var non e' una costante quindi square(var) non lo e'
    const double max3 = 1.4 * square(var);        // OK: puo' essere valutata in fase di esecuzione

    // quando vogliamo che una funzione sia usata solo per la valutazione in fase di compilazione, la dichiariamo
    // consteval anziche' constexpr
    //consteval double square2(double x) { return x*x; }
    constexpr double max4 = 1.4 * square2(17);  // OK: e' un espressione costante
    //const double max5 = 1.4*square2(var);       // errore: var non e' una costante
    std::cout << max3;
    return 0;
}

// le funzioni constexpr e consteval sono la versione C++ della nozione di funzioni pure. Non hanno effetti collaterali
// e possono utilizzare solo le informazioni trasmesse loro come argomenti. In particolare, non possono modificare
// variabili non locali, ma possono avere cicli e utilizzare le proprie variabili locali

constexpr double nth(double x, int n) {
    double res = 1;
    int i = 0;
    while (i<n) {
        res *= x;
        ++i;
    }
    return res;
}
