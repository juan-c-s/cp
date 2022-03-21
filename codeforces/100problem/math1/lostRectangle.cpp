
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long num;
    cin >> num;
    ll answer = 0;
    for (int i = sqrt(num) + 1; i > 0; i--)
    {
        if (num % i == 0)
        {
            answer = ((num / i) * 2) + (i * 2);
            break;
        }
    }
    cout << answer << "\n";
}