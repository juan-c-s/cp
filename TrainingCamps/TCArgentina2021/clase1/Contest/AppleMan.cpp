
#include <string>
#include <iostream>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int checkSurroundings(vector<vector<char> > matriz, char c, int i, int j)
{
    int m = matriz.size();
    int n = matriz[0].size();

    int contador = 0;

    if (i + 1 < m && matriz[i + 1][j] == 'o')
    {
        contador++;
    }
    if (i - 1 >= 0 && matriz[i - 1][j] == 'o')
    {
        contador++;
    }
    if (j - 1 >= 0 && matriz[i][j - 1] == 'o')
    {
        contador++;
    }
    if (j + 1 < n && matriz[i][j + 1] == 'o')
    {
        contador++;
    }
    return contador;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string line;
    cin >> n;
    vector<vector<char> > m;

    getline(cin, line);
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);

        vector<char> ch;
        for (int i = 0; i < line.length(); i++)
        {
            ch.push_back(line[i]);
        }
        m.push_back(ch);
    }
    bool odd = false;

    for (int i = 0; i < m.size() && !odd; i++)
    {
        for (int j = 0; j < m[0].size() && !odd; j++)
        {
            char curr = m[i][j];

            int adjacent = checkSurroundings(m, curr, i, j);

            if (adjacent % 2 != 0)
            {
                odd = true;
                cout << "NO\n";
            }
        }
    }

    if (!odd)
        cout << "YES\n";
}