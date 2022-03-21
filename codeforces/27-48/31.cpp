

#include <iostream>
#include <string>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
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
    int N, total = 0, ans = 0;
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        int num;
        cin >> num;
        total += num;
    }

    for (int i = 1; i <= 5; i++)
    {
        if ((total + i) % (N + 1) != 1)
            ans++;
    }

    cout << ans << endl;
}