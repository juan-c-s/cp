

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
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int meals = 1;
    int camino = 0;
    char pos = 'R';

    while (meals != n)
    {
        meals++;
        if (pos == 'R')
        {
            if (a > b)
            {
                camino += b;
                pos = 'E';
            }
            else
            {
                camino += a;
                pos = 'O';
            }
        }
        else if (pos == 'E')
        {
            if (b > c)
            {
                camino += c;
                pos = 'O';
            }
            else
            {
                camino += b;
                pos = 'R';
            }
        }
        else if (pos == 'O')
        {
            if (a > c)
            {
                camino += c;
                pos = 'E';
            }
            else
            {
                camino += a;
                pos = 'R';
            }
        }
    }
    cout << camino << endl;
}