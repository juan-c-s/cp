

#include <iostream>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
vector<int> dp;
long long mod = 1000000007;
long long dice(int n)
{
    if (n == 1 || n == 0)
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
    for (int i = 1; i <= 6; i++)
    {
        sum += dice(n - i);
    }
    return dp[n] = sum % mod;
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    dp.resize(n + 1, 0);
    long long ans = dice(n) % mod;
    cout << ans << endl;
}