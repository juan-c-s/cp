

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

vector<int> ranks, parent;
void makeSet(int v)
{
    parent[v] = v;
    ranks[v] = 0;
}
int findSet(int v)
{
    int rep = parent[v] == v ? v : parent[findSet(parent[v])];
    parent[v] = rep; //instead of having a larger range, and ask each representant which is the root, well, just link the node with the root
    //itself so next query is much less
    return rep;
};
void unionSets(int a, int b)
{
    int setA = findSet(a);
    int setB = findSet(b);
    if (setA != setB)
    {
        if (ranks[setA] < ranks[setB])
            swap(setA, setB);
        parent[setB] = setA;
        if (ranks[setA] == ranks[setB])
        {
            ranks[setA]++;
        }
    }
}
struct Edge
{
    int w, v, u;
    Edge(int uu, int vv, int ww)
    {
        u = uu;
        v = vv;
        w = ww;
    }
    //THIS OVERLOADED FUNCTION IS NEEDED TO USE THE STL SORT
    bool operator<(Edge const &other) const
    {
        return w < other.w;
    }
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int nodos, aristas, x, y, w;

    cin >> nodos >> aristas;

    vector<Edge> edges;
    for (int i = 0; i < aristas; i++)
    {
        cin >> x >> y >> w;
        edges.push_back(Edge(x, y, w));
    }

    int cost = 0;
    ranks.resize(nodos);
    parent.resize(nodos);

    for (int i = 0; i < nodos; i++)
    {
        makeSet(i);
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < aristas; i++)
    {
        Edge e = edges[i];
        cout << i << ": (" << e.u << ", " << e.v << ", " << e.w << "\n";
    }

    for (int i = 0; i < edges.size(); i++)
    {
        Edge e = edges[i];
        //<------- THIS DISCARDS THE CICLES IN THE ALGORITHM NOW THAT IF TWO NODES ARE IN THE SAME SET, THEY DO NOT CONNECT
        if (findSet(e.u) != findSet(e.v))
        {
            cost += e.w;
            unionSets(e.u, e.v);
        }
    }
    cout << cost << "\n";
}