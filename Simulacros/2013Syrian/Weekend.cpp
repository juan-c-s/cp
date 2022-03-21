

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
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

    int N, V, E, A, a, b, T; //V = Vertices, E = vias tren(edges), A = amigos, T = tiempo
    cin >> N;
    for (int z = 0; z < N; z++)
    {
        cin >> V >> E >> A;
        vector<vector<int> > graph(V, vector<int>(V, INF));
        vector<int> amigos(A);
        for (int i = 0; i < E; i++)
        {
            cin >> a >> b >> T;
            graph[a - 1][b - 1] = graph[b - 1][a - 1] = min(graph[a - 1][b - 1], T); //If they enter 2 edges we'll want the smallest
        }
        for (int j = 0; j < A; j++)
        {
            int num;
            cin >> num;
            amigos[j] = num - 1;
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
        vector<int> caminoMasCorto(A);
        int distanciaMinima = INF;
        do
        {
            // for (int i = 0; i < amigos.size(); i++)
            // {
            //     cout << amigos[i] << ", ";
            // }
            // cout << "\n";

            // RAYA;
            int distanciaTemporal = graph[0][amigos[0]];
            for (int i = 1; i < amigos.size(); i++)
            {
                distanciaTemporal += graph[amigos[i - 1]][amigos[i]];
            }

            distanciaTemporal += graph[amigos[amigos.size() - 1]][V - 1];
            // DBG(distanciaTemporal);
            // RAYA;
            if (distanciaTemporal < distanciaMinima)
            {
                distanciaMinima = distanciaTemporal;
                caminoMasCorto = amigos;
            }
        } while (next_permutation(amigos.begin(), amigos.end()));
        // cout << 1 << " -> ";
        // for (int i = 0; i < A; i++)
        // {
        //     cout << caminoMasCorto[i] + 1 << " -> ";
        // }
        // cout << V << "\n";
        cout << "Case " << z + 1 << ": " << distanciaMinima << "\n";
    }
}