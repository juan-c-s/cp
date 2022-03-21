

#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <unordered_map>

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
    vector<vector<char> > m(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    bool even = true;
    for (int i = 0; i < n && even; i++)
    {

        for (int j = 0; j < n; j++)
        {

            int countAdjo = 0;
            if (j + 1 < n && m[i][j + 1] == 'o')
            {
                countAdjo++;
            }
            if (j - 1 >= 0 && m[i][j - 1] == 'o')
            {
                countAdjo++;
            }
            if (i + 1 < n && m[i + 1][j] == 'o')
            {
                countAdjo++;
            }
            if (i - 1 >= 0 && m[i - 1][j] == 'o')
            {
                countAdjo++;
            }
            if (countAdjo % 2 == 1)
            {
                cout << "NO\n";
                even = false;
                break;
            }
        }
    }
    if (even)
    {

        cout << "YES\n";
    }
}
