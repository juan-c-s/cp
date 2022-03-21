

#include <iostream>
#include <string>

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

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        string line = "";
        for (int j = m - 1; j >= 0; j--)
        {
            line += to_string(j + 1) + " ";
        }
        cout << line << endl;
    }
}