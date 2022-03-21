

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

    //1 = wasteLand; 2 = carrot; 3 = Kiwi; 4 = Grapes

    int n, m, k, t, x, y; //n = filas; m = columnas; k = WastedLand; t = QueriesCrop
    cin >> n >> m >> k >> t;

    vector<vector<int> > field(n, vector<int>(m));
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        field[x][y] = 1;
    }
    int prev = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 1)
            {
                continue;
            }
            else
            {
                if (prev == 2)
                {
                    field[i][j] = 3;
                    prev = 3;
                }
                else if (prev == 3)
                {
                    field[i][j] = 4;
                    prev = 4;
                }
                else if (prev == 4)
                {
                    field[i][j] = 2;
                    prev = 2;
                }
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        if (field[x][y] == 1)
        {
            cout << "Waste\n";
        }
        else if (field[x][y] == 2)
        {
            cout << "Carrots\n";
        }
        else if (field[x][y] == 3)
        {
            cout << "Kiwis\n";
        }
        else if (field[x][y] == 4)
        {
            cout << "Grapes\n";
        }
    }
};