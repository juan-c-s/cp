

#include <iostream>
#include <set>
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
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        int mini = arr[N - 1], cont = 0;
        for (int j = N - 2; j >= 0; j--)
        {
            if (arr[j] > mini)
            {
                cont++;
            }
            else if (arr[j] < mini)
            {
                mini = arr[j];
            }
        }
        cout << cont << endl;
    }
}