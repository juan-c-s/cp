
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll nearlyLucky;
    cin >> nearlyLucky;

    ll N = log10(nearlyLucky);

    ll cont = 0;
    for (int i = 0; i < N + 1; i++)
    {
        if ((((nearlyLucky % 10) == 4) || ((nearlyLucky % 10) == 7)))
        {
            cont++;
        }
        nearlyLucky /= 10;
    }

    cout << (cont == 7 || cont == 4 ? "YES\n" : "NO\n");
}