

#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl
#define ll long long

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, N;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        map<ll, ll> repetidos; //primero entero es la key(numero que se repite), segundo entero es la cantidad de veces
        int szs;
        for (int j = 0; j < N; j++)
        {
            cin >> szs;
            repetidos[szs - j]++;
        }
        bool printed = false;
        ll cont = 0;
        for (map<ll, ll>::iterator it = repetidos.begin(); it != repetidos.end(); it++)
        {
            if (it->second > 1)
            {
                cont += (pow(it->second, 2) - it->second) / 2;
            }
        }

        cout << cont << "\n";
    }
}