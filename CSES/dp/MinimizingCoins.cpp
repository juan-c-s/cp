

#include <iostream>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
vector<int> dp(1000000);

int coin(vector<int> &arr, int value)
{

    if (value == 0)
        return 0;
    else if (value < 0)
        return INF;
    else if (dp[value] != 0)
    {

        return dp[value];
    }
    int minimum = INF;
    for (int i = 0; i < arr.size(); i++)
    {

        minimum = min(minimum, coin(arr, value - arr[i]) + 1);
    }
    return dp[value] = minimum;
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, value;
    cin >> n >> value;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = coin(arr, value);
    if (ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}