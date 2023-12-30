#include <iostream>
#include <string>
#include <complex>

using namespace std;

struct Entry{
    string name;
    int value;
};

Entry read_entry(istream& is)
{
    string s;
    int i;
    is >> s >> i;
    return {s, i};
}

int main() {
    /*auto e = read_entry(cin);
    cout << '{' << e.name << ", " << e.value << "}\n";*/
    // oppure
    //auto [name, value] = read_entry(cin); //associazione strutturata
    //cout << '{' << name << ", " << value << "}\n";

    complex<int> z{1,2};
    //auto[re,im] = z+2; non funge ERRORE LIBRO?
    return 0;
}
