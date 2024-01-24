//
// Created by coppolecchia on 1/24/2024.
//

#ifndef INC_2ND_SCRATCH_TOKENSTREAM_H
#define INC_2ND_SCRATCH_TOKENSTREAM_H

class Token {
public:
    char kind; // usiamo 8 per indicare il tipo numerico
    double value;
};

class TokenStream {
private:
    bool full{false};
    Token buffer;
public:
    Token get();
    void putback(Token t);
};

#endif //INC_2ND_SCRATCH_TOKENSTREAM_H
