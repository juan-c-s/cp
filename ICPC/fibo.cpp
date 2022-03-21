

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>

#define DBG(x) cerr < < #x < < " = " << (x) < < endl;
#define RAYA cerr << "=============================" << endl;
#define ll unsigned long long
#define MAX 101

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

// string cantidad(int N, string patron)
// {
//     if (!s[N].empty())
//     {
//         return s[N];
//     }
//     s[N] = cantidad(N - 1, patron) + cantidad(N - 2, patron);
//     c[N] = count(s[N - 1], patron) + count(s[N - 2], patron);
//     return s[N];
// };
int contar(string binario, string patron)
{
    int M = binario.size();
    int N = patron.size();
    int respuesta = 0;
    for (int i = 0; i <= M - N; i++) // vamos iterando cada posición en el string binario y la comparamos con cada letra del patrón
    {
        int j;
        for (j = 0; j < N; j++)
        {
            if (binario[i + j] != patron[j]) // Al no ser iguales, hacemos un break para despues verificar si habíamos encontrado una ocurrencia
                break;
        }
        if (j == N)
        {
            respuesta++;
            j = 0;
        }
    }
    return respuesta;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> ocurrences(MAX);

    string n, binary;
    while (getline(cin, n) && !n.empty())
    {
        vector<string> s(MAX);
        vector<ll> c(MAX);
        int N = stoi(n);
        getline(cin, binary);
        s[0] = "0";
        s[1] = "1";
        for (int i = 2; i < 10; i++)
        {
            s[i] = s[i - 1] + s[i - 2];
            c[i] = contar(s[i - 1], binary) + contar(s[i - 2], binary);
        }
        // if ((10 < N))
        //     for (int i = 10; i <= N; i++)
        //     {
        //         c[i] = c[i - 1] + c[i - 2];
        //     }
        cout << c[N] << endl;
    }
}
