

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1
#define MIN -1e7

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
vector<vi> matrix;
int cont = 0;
void dfs(int x, int y, int n, int m)
{
    if (x >= n || y >= m || y < 0 || x < 0)
        return;
    if (matrix[x][y] == 0)
        return;
    // DBG(matrix[x][y]);
    matrix[x][y] = 0;
    cont++;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i], n, m);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int R, C, mx = MIN;
        cin >> R >> C;
        matrix.resize(R, vi(C));
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                cin >> matrix[j][k];
            }
        }

        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (matrix[j][k] == 1)
                {

                    cont = 0;
                    dfs(j, k, R, C);
                    mx = max(cont, mx);
                }
            }
        }

        cout << "Case #" << i + 1 << ": " << mx << "\n";
        matrix.clear();
    }
}