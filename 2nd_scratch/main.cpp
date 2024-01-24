/*
 * Grammar
 * Expression:
 *  Term
 *  Expression "+" Term
 *  Expression "-" Term
 * Term:
 *  Primary
 *  Term "*" Primary
 *  Term "/" Primary
 *  Term "%" Primary
 * Primary:
 *  Number
 *  "(" Expression ")"
 * Number:
 *  floating-point-literal
 */

#include <iostream>
#include <vector>
#include "TokenStream.h"

TokenStream ts;
Token get_token(); //function to read token from cin
double expression();
double primary();
double term();

int main()
{
    try{
        double val = 0;
        while(std::cin){
            Token t = ts.get();

            if(t.kind == 'q') break;
            if(t.kind == ';') {
                std::cout << "=" << val << std::endl;
            }else{
                ts.putback(t);
            }
            val = expression();
        }
    }catch (std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }catch (...) {
        std::cerr << "Exception\n";
        return 2;
    }
    return 0;
}

double primary()    // deal with numbers and parenthesis
// calls expression() and get_token()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw std::logic_error{"Missing ')' parenthesis!"};
        return d;
    }
    case '8':
        return t.value;
    default:
        throw std::logic_error{"Primary expected!"};
    }
}

double term()       // deal with *, /, %
{
    double left = primary();
    Token t = ts.get();
    while(true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) throw std::logic_error("Divide by zero");
            left /= d;
            t = ts.get();
        }
            break;
        default:
            return left;
        }
    }
}

double expression() // deal with + and -
{
    double left = term();  // restituisce un termine (numero o risultato di un espressione)
    Token t = ts.get();
    while(true)
    {
        switch (t.kind)
        {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            return left;
        }
    }
}
