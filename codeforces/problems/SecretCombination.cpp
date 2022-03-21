

#include <iostream>
#include <algorithm>
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

    int n, num, index0 = -1, indexSmallest, smallest = 1001;
    cin >> n >> num;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = num % 10;

        num /= 10;
    }
    for (int i = 0; i < n; i++)
    {
    }
}