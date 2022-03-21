#include <iostream>
#include <vector>
#include <queue>

//BFS sirve para encontrar caminos cortos en grafos no ponderados(Sin peso)
using namespace std;
vector<bool> visited;
vector<vector<int> > graph;

void dfs(int s) //s = nodo
{
    if (visited[s])
        return;
    visited[s] = true;

    for (int i = 0; i < graph[s].size(); i++)
    {
        dfs(graph[s][i]);
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    graph.resize(n);

    visited.resize(n);

    for (int j = 0; j < m; j++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); //Grafo sin peso
    }

    //<-------------- DFS ----------------->

    visited[0] = true;
    dfs(0);
};