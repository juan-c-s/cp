

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
    int N; //NUMBER OF FLATS
    cin >> N;
    vector<int> v(N);
    bool one = false, zero = false;
    int adjustments = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        if (v[i] == 0 && zero)
        {
            zero = false;
            one = false;
        }
        if (v[i] == 1 && !zero)
        {
            one = true;
        }
        else if (v[i] == 0 && one)
        {
            zero = true;
        }
        else if (v[i] == 1 && zero)
        {
            one = false;
            zero = false;
            v[i] = 0;
            adjustments++;
        }
    }
    cout << adjustments << endl;
}