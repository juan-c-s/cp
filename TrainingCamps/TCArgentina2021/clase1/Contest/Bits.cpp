#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

#include <iostream>
#include <string>

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

    string bits;
    cin >> bits;

    int contador = 0;
    bool cero = false;
    for (int i = 0; i < n && !cero; i++)
    {
        if (bits[i] == '1')
        {
            contador++;
        }
        else if (bits[i] == '0')
        {
            cout << ++contador << endl;
            cero = true;
        }
    }
    if (!cero)
        cout << contador << "\n";
}