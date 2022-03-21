

#include <iostream>
#include <string>
#include <vector>

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
    short N, cont = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;

        if (line.find("++") != string::npos)
        {
            cont++;
        }
        else
            cont--;
    }
    cout << cont << endl;
}