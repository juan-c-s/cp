
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int x1, p1, x2, p2, digits1, digits2;
        cin >> x1 >> p1 >> x2 >> p2;
        digits1 = (int)(log10(x1) + 1);
        digits2 = (int)(log10(x2) + 1);
        if (digits1 + p1 > digits2 + p2)
        {
            cout << ">\n";
        }
        else if (digits1 + p1 < digits2 + p2)
        {
            cout << "<\n";
        }
        else
        {

            if (digits1 > digits2)
            {
                x2 *= pow(10, digits1 - digits2);
            }
            else if (digits1 < digits2)
            {
                x1 *= pow(10, digits2 - digits1);
            }
            x1 > x2 ? cout << ">\n" : x1 < x2 ? cout << "<\n"
                                              : cout << "=\n";
        }
    }
}

3 6 1 3 8

    k =
        ? k = 2 1 2 3 4 8 9 1 1 1 1 1 1

          3 5 1 2 9 k = 2

          1 2 3 9 10 1 1 1 1 1
