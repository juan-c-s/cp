

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<char> > m;
vector<pair<int, int> > subgraph;

int cont = 0;

void dfs(int x, int y)
{
    if (x >= m.size() || x < 0 || y >= m[0].size() || y < 0)
        return;
    if (m[x][y] == '#')
        return;
    // DBG(m[x][y]);
    // DBG(x);
    // DBG(y);
    m[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
    subgraph.push_back(pair<int, int>(x + 1, y + 1));
    cont++;
};

struct pairhash
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    for (int w = 0; w < T; w++)
    {
        cout << "Case " << w + 1 << ":\n";
        m.clear();
        int R, C, queries = 0;
        cin >> C >> R;
        m.resize(R, vector<char>(C));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                char let;
                cin >> let;
                m[i][j] = let;
            }
        }
        cin.ignore();
        cin >> queries;
        unordered_map<pair<int, int>, int, pairhash> costs;
        // costs[pair<int, int>(5, 6)] = 10;
        // cout << costs[pair<int, int>(5, 6)] << endl;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (m[i][j] == '.')
                {
                    dfs(i, j);
                    for (int z = 0; z < subgraph.size(); z++)
                    {
                        costs[subgraph[z]] = cont;
                        // DBG(subgraph[i].first);
                        // DBG(subgraph[i].second);
                    }
                    cont = 0;
                    subgraph.clear();
                }
            }
        }
        // for (int i = 0; i < R; i++)
        // {
        //     for (int j = 0; j < C; j++)
        //     {
        //         cout << m[i][j];
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < queries; i++)
        {
            int x, y;
            cin >> x >> y;
            cout << costs[pair<int, int>(x, y)] << "\n";
        }
    }
}