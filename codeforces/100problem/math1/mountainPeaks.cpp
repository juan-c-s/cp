
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;
#define MAX 1e5 + 1

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
        {
            m[i] = 1;
        }
    }

    if (m.size() > 0)
    {
        int minMov = n;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                bool hasPeak = false;
                for (int j = 0; j < n; j++)
                {
                    if (m[j])
                    {
                        hasPeak = true;
                    }
                    if ((j + 1) % (i) == 0 && hasPeak && j != n - 1)
                    {
                        hasPeak = false;
                    }
                    else if ((j + 1) % (i) == 0 && !hasPeak)
                    {
                        break;
                    }
                }
                if (hasPeak)
                {
                    minMov = i;
                    break;
                }
            }
        }

        cout << n / minMov << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}