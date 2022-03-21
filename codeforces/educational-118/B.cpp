
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        int mini = MAX, minIndex = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            if (arr[i] < mini)
            {
                minIndex = i;
                mini = arr[i];
            }
        }

        int index = 0;
        for (int i = 0; i < N && index < N / 2; i++)
        {
            if (i == minIndex)
                continue;

            index++;
            cout << arr[i] << " " << mini << endl;
        }
    }
}