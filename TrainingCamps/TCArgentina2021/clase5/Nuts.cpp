

#include <iostream>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int level = 1;
    for (int i = 0; i < n; i++)
    {
        if (level == 1)
        {
            ans += 1 + arr[i];
        }
        else if (arr[i] == 1)
        {
            ans += level - 1 + 2; //bajar todos los niveles y saltar y comer
        }
        else if (level > arr[i])
        {
            ans += level - arr[i] + 1 + 1; //baja al mismo nivel y salta y se come la nuez
        }
        else if (level == arr[i])
        {
            ans += 2;
        }
        else
            ans += 1 + arr[i] - level + 1; //Salta y sube la diferencia de level y arr[i] y come nuez

        level = arr[i];
    }

    cout << ans << endl;
}