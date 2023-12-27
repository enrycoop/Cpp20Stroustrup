#include <iostream>
#include <variant>

/*
 * Una union e'una struct in cui tutti i membri sono allocati allo stesso indirizzo, cosi che la union occupi solo
 * lo spazio del suo membro piu' grande. Naturalmente una union puo' contenere un valore soltanto per un membro alla
 * volta.
 * union Value {
 *   Node* p;
 *   int i;
 *   Node* p;      // usa p se t==Type::ptr
 *   int i;        // usa i se t==Type::num
 * };
 */

using namespace std;

class Node { string name; };
enum class Type { ptr, num };
union Value {
    Node* p;
    int i;
};

struct Entry {
    string name;
    Type t;
    Value v;  // usa
};

/*
 * E'possibile utilizzare il tipo della libreria standard, variant, per eliminare la maggior parte degli usi diretti
 * delle unioni.
 * Una variant memorizza un valore di uno di un insieme di tipi alternativi. Per esempio variant<Node*, int> puo'
 * contenere un Node* o un int.
 */

struct Entry1 {
    string name;
    variant<Node*, int> v;
};


int main() {
    auto* pe= new Entry1("enr", 2);

    if (holds_alternative<int>(pe->v)) {
        cout << get<int>(pe->v);
    }

    return 0;
}
