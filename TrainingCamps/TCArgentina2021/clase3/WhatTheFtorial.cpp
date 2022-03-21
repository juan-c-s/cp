

#include <iostream>
#include <math.h>

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

    int n;
    cin >> n;
    if (n <= 1)
        cout << "1\n";

    else
    {
        double count = 0.0;
        for (int i = 2; i <= n; i++)
        {
            count += log10(i);
        }
        int digits = floor(count) + 1;
        cout << digits << endl;
    }
}