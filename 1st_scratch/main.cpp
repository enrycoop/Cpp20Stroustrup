#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter expression (we can handle +,-,* and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval = 0;
    int rval;
    cin >> lval;

    if (!cin)
    {
        cerr << "no first operand\n";
    }
    for (char op; cin >> op;)
    {
        if(op!='x') cin >> rval;
        if(!cin) cerr << "no second operand\n";
        switch(op) {
        case '+':
            lval += rval;
            break;
        case '*':
            lval *= rval;
            break;
        case '-':
            lval -= rval;
            break;
        case '/':
            lval /= rval;
            break;
        default:
            cout << "Result: " << lval << '\n';
            return 0;
        }
    }
}
