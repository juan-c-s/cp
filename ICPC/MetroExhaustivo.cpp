

#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl
#define INF 10e6 //cota superior es 30

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int V, E, Q, a, b, T; //V = Vertices, E = vias tren(edges), Q = queries, T = tiempo
    cin >> V >> E >> Q;
    vector<vector<int> > graph(V, vector<int>(V, INF));
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> T;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = min(graph[a - 1][b - 1], T); //If they enter 2 edges we'll want the smallest
    }
    for (int i = 0; i < V; i++) // time from a station to itself is 0
        graph[i][i] = 0;

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        cout << "\n"
             << graph[a - 1][b - 1] << "\n";
    }
}