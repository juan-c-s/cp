

#include <iostream>
#include <string>
#include <unordered_map>

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
    cin >> n >> m;
    string line;
    cin.ignore();
    int oddLines = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        if (stoi(line, 0, 2))
            oddLines++;
    }
    cout << oddLines << endl;
}