

#include <iostream>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
vector<long long> dp(2000000);
long long mod = 1000000007;
// long long coin(vector<int> &arr, long long value)
// {
//     if (value == 0)
//         return 1;
//     else if (value < 0)
//         return 0;
//     else if (dp[value] != 0)
//     {
//         return dp[value];
//     }
//     long long sum = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         long long c = coin(arr, value - arr[i]);
//         sum += c;
//     }

//     return dp[value] = sum % mod;
// }
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, value;
    cin >> n >> value;

    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // if (n == 1 && value > n)
    // {
    //     ans = 1;
    // }
    // else
    //     ans = coin(arr, value) % mod;

    dp[0] = 1;
    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                dp[i] += dp[i - arr[j]];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[value] % mod << endl;
}