

#include <iostream>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

vector<bool> visited;
vector<vector<char> > graph;
int n, m;

void dfs(int i, int j) //s = nodo

{
    if (graph[i][j] == '.')
    {
        graph[i][j] = '#';
        if (i + 1 < n)
            dfs(i + 1, j);
        if (j + 1 < m)
            dfs(i, j + 1);
        if (i - 1 >= 0)
            dfs(i - 1, j);
        if (j - 1 >= 0)
            dfs(i, j - 1);
    }
    else
        return;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(m);
    }

    string line;
    getline(cin, line); //reading the rest of the first line

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = line[j];
        }
    }

    //<-------------- DFS ----------------->
    int componentes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] != '#')
            {

                dfs(i, j);
                componentes++;
            }
        }
    }
    cout << componentes << endl;
};

// int main()
// {
//     //Usar las siguientes líneas de código para mejorar flujos I/O
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n >> m;
//     graph.resize(n);
//     distances.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         distances[i].resize(m);
//         graph[i].resize(m);
//     }
//     pair<int, int> A;
//     pair<int, int> B;
//     string line;
//     getline(cin, line); //reading the rest of the first line

//     for (int i = 0; i < n; i++)
//     {
//         getline(cin, line);
//         for (int j = 0; j < m; j++)
//         {
//             if (line[j] == 'A')
//             {
//                 A.first = i;
//                 A.second = j;
//             }
//             else if (line[j] == 'B')
//             {
//                 B.first = i;
//                 B.second = j;
//             }
//             graph[i][j] = line[j];
//         }
//     }

//     //<-------------- BFS ----------------->
//     queue<pair<int, int> > q;
//     q.push(A);
//     distances[A.first][A.second].first = 0;
//     string path = "";
//     while (!q.empty())
//     {
//         pair<int, int> curr = q.front();
//         q.pop();
//         int x = curr.first;
//         int y = curr.second;

//         //<--------------------- Arriba ---------------------->
//         if (x - 1 >= 0)
//         {
//             if (graph[x - 1][y] == '.')
//             {
//                 graph[x - 1][y] = '#';
//                 if (distances[x - 1][y].first == 0)
//                 {
//                     distances[x - 1][y].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x - 1][y].first)
//                 {
//                     distances[x - 1][y].first = distances[x][y].first + 1;
//                     distances[x - 1][y].second = distances[x][y].second + 'U';
//                 }
//                 pair<int, int> s(x - 1, y);
//                 q.push(s);
//                 path += 'U';
//             }
//             else if (graph[x - 1][y] == 'B')
//             {
//                 if (distances[x - 1][y].first == 0)
//                 {
//                     distances[x - 1][y].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x - 1][y].first)
//                 {
//                     distances[x - 1][y].first = distances[x][y].first + 1;
//                     distances[x - 1][y].second = distances[x][y].second + 'U';
//                 }

//                 path += 'U';
//             }
//         }
//         //<--------------------- Abajo ---------------------->
//         if (x + 1 < n)
//         {
//             if (graph[x + 1][y] == '.')
//             {
//                 graph[x + 1][y] = '#';
//                 if (distances[x + 1][y].first == 0)
//                 {
//                     distances[x + 1][y].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x + 1][y].first)
//                 {
//                     distances[x + 1][y].first = distances[x][y].first + 1;
//                     distances[x + 1][y].second = distances[x][y].second + 'D';
//                 }
//                 pair<int, int> s(x + 1, y);
//                 q.push(s);
//                 path += 'D';
//             }
//             else if (graph[x + 1][y] == 'B')
//             {
//                 if (distances[x + 1][y].first == 0)
//                 {
//                     distances[x + 1][y].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x + 1][y].first)
//                 {
//                     distances[x + 1][y].first = distances[x][y].first + 1;
//                     distances[x + 1][y].second = distances[x][y].second + 'D';
//                 }

//                 path += 'D';
//             }
//         }

//         //<--------------------- Izquierda ---------------------->
//         if (y - 1 >= 0)
//         {
//             if (graph[x][y - 1] == '.')
//             {
//                 graph[x][y - 1] = '#';
//                 if (distances[x][y - 1].first == 0)
//                 {
//                     distances[x][y - 1].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x][y - 1].first)
//                 {
//                     distances[x][y - 1].first = distances[x][y].first + 1;
//                     distances[x][y - 1].second = distances[x][y].second + 'L';
//                 }
//                 pair<int, int> s(x, y - 1);
//                 q.push(s);
//                 path += 'L';
//             }
//             else if (graph[x][y - 1] == 'B')
//             {
//                 if (distances[x][y - 1].first == 0)
//                 {
//                     distances[x][y - 1].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x][y - 1].first)
//                 {
//                     distances[x][y - 1].first = distances[x][y].first + 1;
//                     distances[x][y - 1].second = distances[x][y].second + 'L';
//                 }
//                 path += 'L';
//             }
//         }
//         //<--------------------- Derecha ---------------------->

//         if (y + 1 < m)
//         {
//             if (graph[x][y + 1] == '.')
//             {
//                 graph[x][y + 1] = '#';
//                 if (distances[x][y + 1].first == 0)
//                 {
//                     distances[x][y + 1].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x][y + 1].first)
//                 {
//                     distances[x][y + 1].first = distances[x][y].first + 1;
//                     distances[x][y + 1].second = distances[x][y].second + 'R';
//                 }
//                 pair<int, int> s(x, y + 1);
//                 q.push(s);
//                 path += 'R';
//             }

//             else if (graph[x][y + 1] == 'B')
//             {
//                 if (distances[x][y + 1].first == 0)
//                 {
//                     distances[x][y + 1].first = distances[x][y].first + 1;
//                 }
//                 else if (distances[x][y].first + 1 > distances[x][y + 1].first)
//                 {
//                     distances[x][y + 1].first = distances[x][y].first + 1;
//                     distances[x][y + 1].second = distances[x][y].second + 'R';
//                 }
//                 path += 'R';
//             }
//         }
//     }
//     if (distances[B.first][B.second].first > 0)
//     {
//         cout << "YES\n"
//              << distances[B.first][B.second].first << endl
//              << distances[B.first][B.second].second << endl;
//     }
//     else

//         cout << "NO\n"
//              << distances[B.first][B.second].first << endl;
//     //  << (path) << endl;
// };