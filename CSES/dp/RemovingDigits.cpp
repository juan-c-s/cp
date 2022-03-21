

#include <string>
#include <iostream>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
vector<int> dp(INF);

int minSteps(int n)
{
    if (n == 0)
    {
        return 0;
    }

    else if (n / 10 == 0)
    {
        return 1;
    }
    RAYA;
    int best = -1;
    int temp = n;
    int digit = n;
    for (int i = 0; i < n / 10; i++)
    {

        digit = temp % 10; // In this case, the right most number
        if (digit == 0)
            continue;
        if (digit > best)
        {
            best = digit;
        }
        temp /= 10;
    }
    DBG(best);
    RAYA;
    return minSteps(n - best) + 1;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;

    cin >> n;
    int mini = minSteps(n);
    cout << mini << endl;
}