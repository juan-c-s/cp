

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

    int commands;
    cin >> commands;

    string instructions;
    getline(cin, instructions);
    int movements = 0; //movem
    for (int i = 0; i < instructions.length(); i++)
    {
        char currIns = instructions[i];
    }
    return 1;
}