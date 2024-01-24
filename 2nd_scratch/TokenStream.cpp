//
// Created by coppolecchia on 1/24/2024.
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include "TokenStream.h"

Token TokenStream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch(ch){
    case ';':    // for print
    case 'q':    // for quit

    case '(': case ')':
    case '+': case '-': case '*': case '/': case '%':
        return Token{ch};

    case '.': case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        std::cin.putback(ch);    // mette la cifra in input stream
        double val;
        std::cin >> val;
        return Token{'8', val};
    }
    default:
        throw std::logic_error{"Bad token"};

    }
}
void TokenStream::putback(Token t)
{
    if (full) throw std::logic_error{"putback() into a full buffer"};
    buffer = t;
    full = true;
}
