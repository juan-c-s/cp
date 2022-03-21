

#include <iostream>
#include <vector>
#include <string>
#include <map>

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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        int digitA = 0, digitB = 0;
        int num = a;

        while (num / 10 != 0)
        {

            digitA += num % 10;
            num /= 10;
        }
        digitA += num % 10;
        num = b;
        while (num / 10 != 0)
        {

            digitB += num % 10;
            num /= 10;
        }
        digitB += num % 10;
        if ((digitB % 2 == 1 && digitA % 2 == 1) || (digitB % 2 == 0 && digitA % 2 == 0))
        {
            cout << "NOT GOOD\n";
        }
        else
            cout << "GOOD\n";
    }
}
