/*
 * Ambito e Durata
 *
 * Una dichiarazione introduce un nome in un ambito:
 * - AMBITO LOCALE: Un nome dichiarato in una funzione o in una lambda e' chiamato "nome locale".
 *                  Il suo ambito si estende dal punto della sua dichiarazione alla fine del blocco in cui essa avviene.
 *                  Un blocco e' delimitato da una coppia {}.
 *                  I nomi degli argomenti delle funzioni sono considerati nomi locali.
 * - AMBITO DELLA CLASSE: Un nome e' detto "nome del membro" se:
 *                                   -> e' definito in una classe
 *                                   -> all'esterno di qualsiasi funzione
 *                                   -> lambda
 *                                   -> enum class
 *                  Il suo ambito si estende dalla { di apertura della dichiarazione che la racchiude fino alla }
 *                  corrispondente.
 * - AMBITO DEL NAMESPACE: Un nomee' detto "nome del membro del namespace" se:
 *                                   -> e' definito in un namespace
 *                                   -> all'esterno di qualsiasi funzione
 *                                   -> lambda
 *                                   -> classe
 *                                   -> enum class
 *                  Il suo ambito si estende dal punto di dichiarazione alla fine del suo namespace.
 * Un nome non dichiarato all'interno di qualsiasi altro costrutto e' detto "nome globale" e lo si definisce all'interno
 * del "namespace globale".
 *
 * Inoltre sono possibili oggetti senza nome, come gli oggetti temporanei e quelli creati usando "new".
 *
 * Un'oggetto deve essere costruito (inizializzato) prima di essere usato e sara' distrutto alla fine del suo ambito.
 *     Per un oggetto namespace -> la fine del programma
 *     Per un membro            -> punto di distruzione dell'oggetto di cui e' membro
 * Un oggetto creato da "new" vive fino a quando non e' distrutto da "delete".
 *
 */


#include <iostream>
#include <vector>

std::vector<int> vec; // e' globale

struct Record {
    std::string name; // name e' membro di record
};

void fct(int arg) {
    std::string motto {"Who dares wins"}; // motto e' locale
    auto p = new Record{"Hume"}; // p punta a un Record senza nome (creato da new)
}


int main() {

    return 0;
}
