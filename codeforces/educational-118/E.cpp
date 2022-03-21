
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

bool valid(int i, int j, int n, int m)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}

void printMatrix(vector<vector<char> > &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<char> > m(N, vector<char>(M));
        pair<int, int> lab;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == 'L')
                {
                    lab.first = i;
                    lab.second = j;
                }
            }
        }
        queue<pair<char, char> > q;
        q.push(pair<char, char>(lab.first, lab.second));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int validtiles = 0;

            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + curr.first;
                int y = dy[i] + curr.second;
                if (valid(x, y, N, M) && (m[x][y] == '.' || m[x][y] == '+'))
                {
                    validtiles++;
                }
            }
            if (validtiles < 3)
            {
                if (m[curr.first][curr.second] != 'L')
                {
                    m[curr.first][curr.second] = '+';
                }
                for (int i = 0; i < 4; i++)
                {
                    int x = dx[i] + curr.first;
                    int y = dy[i] + curr.second;
                    if (valid(x, y, N, M) && m[x][y] == '.')
                    {
                        q.push(pair<int, int>(x, y));
                    }
                }
            }
        }
        printMatrix(m);
    }
}