

#include <iostream>

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

    int x, y;

    cin >> x >> y;
    bool canPay = true;
    int i = 0;
    while (canPay)
    {
        if (i % 2 == 0)
        {
            //Ciel's turn
            if (x >= 2 && y >= 2)
            {
                x -= 2;
                y -= 2;
            }
            else if (x >= 1 && y >= 12)
            {
                x -= 1;
                y -= 12;
            }
            else if (y >= 22)
            {
                y -= 22;
            }
            else
            {
                canPay = false;
                cout << "Hanako\n";
            }
        }
        else
        {
            //Hanako's turn
            //Ciel's turn

            if (y >= 22)
            {
                y -= 22;
            }
            else if (x >= 1 && y >= 12)
            {
                x -= 1;
                y -= 12;
            }
            else if (x >= 2 && y >= 2)
            {
                x -= 2;
                y -= 2;
            }
            else
            {
                canPay = false;
                cout << "Ciel\n";
            }
        }
        i++;
    }
}