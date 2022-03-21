
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;
#define MAX 1e5 + 1

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = MAX;
    vector<int> sieve(n, 0); //Los primos son los numeros que tienen 0

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

    map<int, int> um;
    bool encontrado = false;
    int size = 0;
    for (int i = 2; i < sieve.size() && !encontrado; i++)
    {
        if (!sieve[i])
        {
            int cont = 0;

            while (num - i >= 0)
            {
                num -= i;
                cont++;
                size++;
            }
            if (cont > 0)
                um[i] = cont;

            if (num == 0)
            {
                encontrado = true;
                break;
            }

            um[i]--;
            num += i;
            size--;
        }
    }
    cout << size << endl;
    for (map<int, int>::iterator i = um.begin(); i != um.end(); i++)
    {
        for (int j = 0; j < i->second; j++)
        {
            cout << i->first << " ";
        }
    }
    cout << endl;
}