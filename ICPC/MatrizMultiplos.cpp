

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
const int MOD = 1e9 + 7;
using ll = long long;
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, filas, columnas;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> filas >> columnas; //∑i∑j = ((n+1)/2) * ((m+1)/2)
        //<---- como los numeros son muy grandes, hay que usar aritmética modular
        long long ll = (filas * (filas + 1) / 2 % MOD) * (columnas * (columnas + 1) / 2 % MOD) % MOD;
        cout << ll << "\n";
    }
}