
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

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
        long long h;
        int n;
        cin >> n >> h;
        vector<long long> arr(n);
        int i = 0, first;
        cin >> first;

        for (int i = 0; i < n - 1; i++)
        {
            int num;
            cin >> num;
            arr[i] = num - first;
            first = num;
        }

        // cout << "[\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << ", ";
        // }
        // cout << "]\n";

        long long hi = 1e18, start = 0, mid = 0;

        while (start + 1 < hi)
        {
            mid = start + (hi - start) / 2;
            long long cont = 0;
            arr[n - 1] = mid;
            for (int i = 0; i < n; i++)
            {
                //∑min(i,k)
                cont += min(arr[i], mid);
            }

            if (cont >= h)
            {
                hi = mid;
            }
            else
            {
                start = mid;
            }
        }

        cout << hi << "\n";
    }
}