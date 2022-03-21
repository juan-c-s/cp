

#include <iostream>
#include <algorithm>
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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max = 0;
    int j = v.size() - 1;
    bool printed = false;
    for (int i = 0; i < n; i++)
    {
        if (v[j] % v[i] == 0)
        {
            continue;
        }
        else
        {
            cout << v[j] % v[i] << endl;
            printed = true;
            break;
        }
    }
    if (!printed)
        cout << "0\n";
}