

#include <iostream>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
bool bounds(int x, int y, int N, int M)
{
    return (x < N) && (x >= 0) && (y < M) && (y >= 0);
}
bool sePuede = false;
bool dfs(int x, int y, char letra, vector<vector<char> > m, int N, int M)
{
    if (letra == 'p')
    {
        if (bounds(x - 1, y - 1, N, M) && m[x - 1][y - 1] == 'i')
        {
            if (dfs(x - 1, y - 1, 'i', m, N, M))
                return true;
        }
        if (bounds(x - 1, y, N, M) && m[x - 1][y] == 'i')
        {
            if (dfs(x - 1, y, 'i', m, N, M))
                return true;
        }
        if (bounds(x - 1, y + 1, N, M) && m[x - 1][y + 1] == 'i') //ARRIBA A LA DERECHA
        {
            if (dfs(x - 1, y + 1, 'i', m, N, M))
                return true;
        }
        if (bounds(x, y - 1, N, M) && m[x][y - 1] == 'i') //IZQUIERDA
        {
            if (dfs(x, y - 1, 'i', m, N, M))
                return true;
        }
        if (bounds(x, y + 1, N, M) && m[x][y + 1] == 'i') //DERECHa
        {
            if (dfs(x, y + 1, 'i', m, N, M))
                return true;
        }
        if (bounds(x + 1, y - 1, N, M) && m[x + 1][y - 1] == 'i') //ABAJO A LA IZQUIERDA
        {
            if (dfs(x + 1, y - 1, 'i', m, N, M))
                return true;
        }
        if (bounds(x + 1, y, N, M) && m[x + 1][y] == 'i') //ABAJO
        {
            if (dfs(x + 1, y, 'i', m, N, M))
                return true;
        }
        if (bounds(x + 1, y + 1, N, M) && m[x + 1][y + 1] == 'i') //ABAJO A LA DERECHA
        {
            if (dfs(x + 1, y + 1, 'i', m, N, M))
                return true;
        }
        }
    else if (letra == 'i')
    {
        if (bounds(x - 1, y - 1, N, M) && m[x - 1][y - 1] == 'e')
        {
            return true;
        }
        if (bounds(x - 1, y, N, M) && m[x - 1][y] == 'e')
        {
            return true;
        }
        if (bounds(x - 1, y + 1, N, M) && m[x - 1][y + 1] == 'e') //ARRIBA A LA DERECHA
        {
            return true;
        }
        if (bounds(x, y - 1, N, M) && m[x][y - 1] == 'e') //IZQUIERDA
        {
            return true;
        }
        if (bounds(x, y + 1, N, M) && m[x][y + 1] == 'e') //DERECHa
        {
            return true;
        }
        if (bounds(x + 1, y - 1, N, M) && m[x + 1][y - 1] == 'e') //ABAJO A LA IZQUIERDA
        {
            return true;
        }
        if (bounds(x + 1, y, N, M) && m[x + 1][y] == 'e') //ABAJO
        {
            return true;
        }
        if (bounds(x + 1, y + 1, N, M) && m[x + 1][y + 1] == 'e') //ABAJO A LA DERECHA
        {
            return true;
        }
    }
    return false;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases, N, M;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> N >> M;
        vector<vector<char> > m(N, vector<char>(M));
        vector<pair<int, int> > pPosiciones;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> m[j][k];
                if (m[j][k] == 'p')
                {
                    pPosiciones.push_back(pair<int, int>(j, k));
                }
            }
        }

        for (int j = 0; j < pPosiciones.size(); j++)
        {
            int x = pPosiciones[j].first;
            int y = pPosiciones[j].second;
            dfs(x, y, m[x][y], m, M, N);
        }
        if (sePuede)
        {
            cout << "Cutie Pie!\n";
        }
        else
            cout << "Sorry Man\n";

        sePuede = false;
    }
}
// int x = pPosiciones[j].first;
//             int y = pPosiciones[j].second;
//             bool subir = true, bajar = true, der = true, izq = true;
//             if (x - 1 < 0)
//                 subir = false;
//             if (x + 1 >= N)
//                 bajar = false;
//             if (y - 1 < 0)
//                 izq = false;
//             if (y + 1 >= M)
//                 der = false;

//             if (subir && izq && m[subir][izq] == 'i')
//             {
//                 subir = true, bajar = true, der = true, izq = true;
//                 if (x - 1 < 0)
//                     subir = false;
//                 if (x + 1 >= N)
//                     bajar = false;
//                 if (y - 1 < 0)
//                     izq = false;
//                 if (y + 1 >= M)
//                     der = false;
//             }