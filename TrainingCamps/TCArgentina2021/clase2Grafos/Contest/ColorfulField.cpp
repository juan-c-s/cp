#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

#include <iostream>
#include <vector>

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
    short k, t;
    unsigned short n, m, x, y, i, j; //n = filas; m = columnas; k = WastedLand; t = QueriesCrop
    cin >> n >> m >> k >> t;

    vector<vector<char> > field(n, vector<char>(m));
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        field[x - 1][y - 1] = 'W';
    }
    char prev = 'G';
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                continue;
            }
            else
            {
                if (prev == 'C')
                {
                    field[i][j] = 'K';
                    prev = 'K';
                }
                else if (prev == 'K')
                {
                    field[i][j] = 'G';
                    prev = 'G';
                }
                else if (prev == 'G')
                {
                    field[i][j] = 'C';
                    prev = 'C';
                }
            }
        }
    }

    for (i = 0; i < t; i++)
    {
        cin >> x >> y;
        if (field[x - 1][y - 1] == 'W')
        {
            cout << "Waste\n";
        }
        else if (field[x - 1][y - 1] == 'C')
        {
            cout << "Carrots\n";
        }
        else if (field[x - 1][y - 1] == 'K')
        {
            cout << "Kiwis\n";
        }
        else if (field[x - 1][y - 1] == 'G')
        {
            cout << "Grapes\n";
        }
    }
};