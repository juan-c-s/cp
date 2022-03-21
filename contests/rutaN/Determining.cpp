#include <iostream>
#include <unordered_map>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    long long sizas = pow(2, 31) - 1;
    long long fibo[10001];
    unordered_map<int, int> map;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        map[fibo[i] % sizas] = 1;
    }
    while (T--)
    {
        long long num;
        cin >> num;
        if (map[num])
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}