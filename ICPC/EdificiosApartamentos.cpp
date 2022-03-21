

#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
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
    int ed, q;
    cin >> ed >> q;
    vector<int> personas(ed + 1);
    int rango = 0;
    for (int i = 0; i < ed; i++)
    {
        cin >> personas[i + 1];
        rango += personas[i + 1];
        personas[i + 1] = rango;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        char query;
        cin >> query >> a >> b;

        if (query == 'q')
        {
            cout << "\n: " << personas[b] << "-" << personas[a - 1] << "= " << personas[b] - personas[a - 1] << "s\n";
        }
        else if (query == 'u')
        {
            for (int i = a; i < personas.size(); i++)
            {
                personas[i] += b;
            }
        }
    }
}