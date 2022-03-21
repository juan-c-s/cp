

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e7

using namespace std;

typedef long long ll;
typedef vector<int> vi;

//estados (peso,i)
//transiciones =>
vector<vi> cost;

vector<vi> dp;
vector<vi> caminos;
int go(int i, int j)
{
    if (j < 0 || i < 0)
    {
        return MAX;
    }
    else if (j == 0 && i == 0)
    {
        return cost[0][0];
    }
    if (dp[i][j] != 0) //si ya lo visitamos
    {
        return dp[i][j];
    }
    dp[i][j] = min(go(i - 1, j), go(i, j - 1)) + cost[i][j];
    return dp[i][j];
};
int ways(int i, int j)
{
    if (j < 0 || i < 0)
        return 0;
    else if (j == 0 && i == 0)
        return 1;
    if (caminos[i][j] != 0)
        return caminos[i][j];

    int mn = go(i, j); //camíno mínimo
    caminos[i][j] = 0;
    if (go(i - 1, j) + cost[i][j] == mn) //se fue para abajo
        caminos[i][j] += ways(i - 1, j);

    if (go(i, j - 1) + cost[i][j] == mn) //camino mínimo cogió para la derecha
        caminos[i][j] += ways(i, j - 1);
    return caminos[i][j];
};

void build(int i, int j)
{
    if (j < 0 || i < 0)
        return;
    else if (j == 0 && i == 0)
        return;

    int mn = go(i, j); //camíno mínimo
    caminos[i][j] = 0;
    if (go(i - 1, j) + cost[i][j] == mn)
    {
        //se fue para abajo
        build(i - 1, j);
        cout << "D";
        return;
    }
    if (go(i, j - 1) + cost[i][j] == mn)
    {
        //se fue para abajo
        build(i, j - 1);
        cout << "R";
        return;
    }

    return;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, C;
    cin >> R >> C;
    dp.resize(R, vi(C, 0));
    cost.resize(R, vi(C));
    caminos.resize(R, vi(C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> cost[i][j];
        }
    }
    int szs = go(R - 1, C - 1);
    // DBG(szs);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    int cam = ways(R - 1, C - 1);
    // DBG(cam);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << caminos[i][j] << " ";
        }
        cout << "\n";
    }

    build(R - 1, C - 1);
}
