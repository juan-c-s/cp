

#include <iostream>
#include <vector>
#include <algorithm>

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
    int cases, N;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> N;
        vector<int> v(N), sum;
        for (int j = 0; j < N; j++)
        {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        int cont = 0, problemas = 0;
        for (int j = 0; j < N; j++)
        {
            if (cont + v[j] <= 300)
            {
                cont += v[j];
                problemas++;
                if (j == 0)
                    sum.push_back(0 + v[j]);
                else
                    sum.push_back(sum[j - 1] + v[j]);
            }
            else
                break;
        }

        cout << problemas << " ";
        cont = 0;
        for (int j = 0; j < sum.size(); j++)
        {
            cont += sum[j];
        }
        cout << cont << endl;
    }
}