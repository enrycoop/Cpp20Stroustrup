#include <iostream>

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t) {
    using enum Traffic_light;

    switch (t) {
        case green:     return t=yellow;
        case yellow:    return t=red;
        case red:       return t=green;
    }
}

int main() {

    // Color x1 = red;  // errore quale red?
    //Color y2 = Traffic_light::red;  // errore non e' un color
    Color z3 = Color::red;
    auto x4 = Color::red;

    //int i = Color::red;             // errore: Color::red non e' un int
    //Color c = 2;                    // errore di inizializzazione: 2 non e' Color
    Color x = Color{5};               // OK, ma prolisso
    Color y {6};                      // OK anche in questo caso

    int x1 = int(Color::red);

    auto signal = Traffic_light::red;
    Traffic_light next = ++signal;     // next diventa green

    return 0;
}
