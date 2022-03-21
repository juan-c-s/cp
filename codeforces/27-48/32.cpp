

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
    int N, M, maxi = -2; //M = candies
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] > M)
        {
            if (maxi != -2)
                maxi = (ceil((float)arr[i] / M) >= ceil((float)arr[maxi] / M)) ? i : maxi;
            else
                maxi = i;
        }
    }
    if (maxi != -2)
    {
        cout << maxi + 1 << endl;
    }
    else
        cout << N << endl;
}