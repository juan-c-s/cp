

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

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
    int N, ans = -1;
    cin >> N; //number of pages on book
    vector<int> week(7);
    for (int i = 0; i < 7; i++)
    {

        cin >> week[i];
    }
    while (N > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            N -= week[i];
            if (N <= 0)
            {
                ans = i + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}