

#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
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
    int n, cont = 0, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
            cont++;
        else
            continue;
    }
    if (n == 1)
    {
        if (num == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else if (cont == n - 1)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }
}