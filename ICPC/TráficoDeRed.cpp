

#include <iostream>
#include <vector>
#include <queue>

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
    int n, m, s, x, y;
    cin >> n >> m >> s; //n = cantidad de computadoras; m = conexiones; s=punto inicial(start)
    vector<vector<int> > v(n, vector<int>());

    vector<int> distancias(n);

    //<------- ESTE PROBLEMA SE HACE CON BFS CONTANDO EN QUÉ PUNTO ESTÁN --------->
    //<------- HACER LISTA PARA GUARDAR ITERADAS PARA LLEGAR A UN NODO ------>
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << i << " -> " << v[i][j] << "\n";
    //     }
    // }

    distancias[s] = 0;

    queue<int> q;
    q.push(s);
    int d = 0;
    while (!q.empty())
    {
        cout << "\ncorre\n";
        int curr = q.front();
        q.pop();
        for (int i = 0; i < v[curr].size(); i++)
        {
            distancias[v[curr][i]] = distancias[curr] + 1;

            q.push(v[curr][i]);
        }
    }
    int last = distancias[0];
    cout << distancias[0] << ": " << 0 << " ";
    for (int i = 1; i < distancias.size(); i++)
    {
        if (i == s)
            continue;
        if (last != distancias[i])
        {

            cout << "\n"
                 << distancias[i] << ": " << i << " ";
            last = distancias[i];
        }
        else
            cout << i << " ";
    }
    cout << "\n";
}