

#include <iostream>
#include <vector>
#include <algorithm>

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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    int hi;
    int lo;
    for (int j = 0; j < m; j++)
    {
        vector<int>::iterator itt = upper_bound(a.begin(), a.end(), b[j]);
        if (itt == a.begin())
        {
            cout << "0 ";
        }
        else
        {
            int index = itt - a.begin();
            cout << index << " ";
        }
    }
    cout << "\n";
}