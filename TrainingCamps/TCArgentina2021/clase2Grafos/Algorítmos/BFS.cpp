#include <iostream>
#include <vector>
#include <queue>

//BFS sirve para encontrar caminos cortos en grafos no ponderados(Sin peso)
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n);

    for (int j = 0; j < m; j++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); //Grafo sin peso
    }

    //<-------------- BFS ----------------->
    // Dado un x, encontraremos el camino mas corto a el resto de nodos con BFS al guardar las distancias
    int distance[n];
    queue<int> cola;
    bool visited[n];

    visited[0] = true;
    cola.push(0);
    while (!cola.empty())
    {
        int curr = cola.front();
        cola.pop();

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int node = graph[curr][i];
            if (visited[node])
                continue;

            visited[node] = true;
            distance[node] = distance[curr] + 1;
            cola.push(node);
        }
    }
};