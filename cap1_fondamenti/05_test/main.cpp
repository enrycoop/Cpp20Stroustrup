/*
 * C++ offre un set convenzionale di istruzioni per esprimere selezione e cicli, come le istruzioni if, switch e
 * i cicli while e for.
 */

#include <iostream>
#include <vector>

using namespace std;

bool accept()
{
    cout << "Vuoi procedere (s o n)?\n";
    char answer = 0;   // inizializza a un valore che non apparira' sull'input
    cin >> answer;     // legge risposta

    if (answer == 'y')
        return true;
    return false;
}

bool accept2()
{
    cout << "Vuoi procedere (s o n)?\n";
    char answer = 0;   // inizializza a un valore che non apparira' sull'input
    cin >> answer;     // legge risposta

    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "Lo prendo come un no.\n";
            return false;
    }
}
struct Point{
    double x;
    double y;
};

void action()
/*
 * Un'istruzione switch testa un valore rispetto a un set di costanti. Quelle costanti, chiamate etichette case, devono
 * essere distinte:
 *  - se il valore testato non corisponde ad alcuna di esse viene scelto default
 *  - Se il valore testato non corrisponde ad alcuna etichetta case e non viene fornito default, non fa niente.
 *
 * Non e' indipensabile uscire da un case tornando dalla funzione che contiene la sua istruzione switch. Come in questa
 * funzione. che e' un parser per un banale video game militare. PEr saltare si usa break;
 */
{
    while (true)
    {
        cout << "inserisci un azione:\n";   // richiede azione
        string act;
        cin >> act;                         // legge caratteri in una stringa
        Point delta {0,0};

        for (char ch : act)
        {
            switch (ch)
            {
                case 'u':      // up
                case 'n':      // north
                    ++delta.y;
                    break;
                case 'r':      // right
                case 'e':      // east
                    ++delta.x;
                    break;
                case 'd':      // down
                case 's':      // south
                    --delta.y;
                    break;
                case 'l':      // left
                case 'o':      // west
                    --delta.x;
                    break;
                default:
                    cout << "I freeze!\n";
            }
            // move(current + delta*scale);
            // update_display();
        }
    }
}

void do_something(vector<int>& v)
{
    if (auto n = v.size(); n!=0) {
        // ...
    }

    // oppure
    if (auto n = v.size()) {
        // ...
    }
}

int main() {

    return 0;
}
