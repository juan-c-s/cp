

#include <iostream>
#include <string>
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
    short N, P, V, T;
    cin >> N;
    vector<int> arr(N);
    for (short i = 0; i < N; i++)
    {
        cin >> P >> V >> T;
        arr[i] = P + V + T;
    }
    short cont = 0;
    for (short i = 0; i < N; i++)
    {
        if (arr[i] >= 2)
        {
            cont++;
        }
    }
    cout << cont << "\n";
}