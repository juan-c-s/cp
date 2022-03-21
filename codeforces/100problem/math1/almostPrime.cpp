
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;
#define MAX 3001

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = MAX;
    vector<int> sieve(MAX, 0); //Los primos son los numeros que tienen 0

    for (int i = 2; i < n; i++)
    {
        if (!sieve[i])
            for (int j = 2 * i; j < n; j += i)
            {
                sieve[j] = 1; //1 = no primo,
            }
    }

      int num;
    cin >> num;
    int suma = 0;
    for (int i = 1; i < num + 1; i++)
    {
        int cont = 0;
        for (int j = 2; j < sieve.size(); j++)
        {
            if (sieve[j] == 0 && (i % j == 0))
            {
                // DBG(j);
                // DBG(i / j);
                cont++;
            }
        }
        if (cont == 2)
        {
            suma++;
        }
    }
    cout << suma << "\n";
}