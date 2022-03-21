

#include <iostream>
#include <vector>
#include <string>
#include <map>

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
    int N, T;
    cin >> N >> T;
    while (N--)
    {
        int x, y, w, z;
        cin >> x >> y >> w >> z;
        if ((x + y) % 2 == (w + z) % 2)
        {
            cout << max(abs(w - x), abs(z - y)) << endl;
        }
        else
            cout << "can't reach!\n";
    }
}
