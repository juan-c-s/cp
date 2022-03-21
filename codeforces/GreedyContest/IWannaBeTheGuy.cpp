

#include <iostream>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, value; //N=levels(1....N)

    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i] = 1; //1 means that it is a unpassed level
    }
    bool szs = true;

    for (int i = 0; i < 2 * M; i++)
    {
        cin >> value;
        v[value - 1] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (v[i])
        {
            szs = false;
            cout << v[i] << endl;
        }
    }
    if (szs)
    {
        cout << "I become the guy.\n";
    }
    else
        cout << "Oh, my keyboard!\n";
}