

#include <iostream>
#include <vector>
#include <string>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
vector<int> dp(1000000);
long long mod = 1000000007;
long long coin(int n, int m, vector<int> &v, int q)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    long long sum = 0;
    for (int i = q; i < m; i++)
    {
        sum += coin(n - v[i], m, v, i);
    }
    return dp[n] = sum % mod;
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    long long ans = coin(n, m, v, 0) % mod;
    cout << ans << endl;
}