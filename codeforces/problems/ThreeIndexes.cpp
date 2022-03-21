

#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl
#define ll long long

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, N;
    cin >> T;

    for (int b = 0; b < T; b++)
    {
        cin >> N;
        vector<int> arr(N);
        for (int a = 0; a < N; a++)
        {
            cin >> arr[a];
        }
        int max = 0, maxIndex = -1;
        for (int j = 0; j < N; j++)
        {
            if (arr[j] > max && a != 0 && a != N - 1)
            {
                max = arr[a];
                maxIndex = a;
            }
        }
    }
}