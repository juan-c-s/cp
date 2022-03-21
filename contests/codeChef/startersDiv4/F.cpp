#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> edges(n, vi(m));
        vector<vi> color3(n, vi(m));
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        edges[x1][y1] = 1;
        edges[x2][y2] = 2;
        color3[x1][y1] = 1;
        color3[x2][y2] = 2;
        // forn(i, n)
        // {
        //     forn(j, m) cout << edges[i][j] << ", ";
        //     cout << el;
        // }
        // RAYA;
        queue<iii> q;
        q.push(make_pair(make_pair(x1, y1), 1));
        vector<vi> visited(n, vi(m));
        bool cambiarColor = false;
        while (!q.empty() && !cambiarColor)
        {
            iii curr = q.front();
            q.pop();
            if (visited[curr.fi.fi][curr.fi.se])
                continue;
            int x = curr.fi.fi, y = curr.fi.se;
            visited[x][y] = 1;
            bool color = curr.se;
            int clr = color ? 1 : 2;
            edges[x][y] = clr;
            color = !color;
            clr = color ? 1 : 2;
            forn(i, 4)
            {
                int dxx = dx[i], dyy = dy[i];
                if (x + dxx >= n || x + dxx < 0 || y + dyy < 0 || y + dyy >= m)
                    continue;
                if (visited[x + dxx][y + dyy])
                    continue;
                if ((!visited[x + dxx][y + dyy]) && (edges[x + dxx][y + dyy] == 0 || edges[x + dxx][y + dyy] == clr))
                {
                    q.push(make_pair(make_pair(x + dxx, y + dyy), color));
                }
                else if (edges[x + dxx][y + dyy] != clr)
                {
                    cambiarColor = true;
                    break;
                }
            }
        }
        // DBG(cambiarColor);
        if (cambiarColor)
        {
            // RAYA;
            // forn(i, n)
            // {
            //     forn(j, m) cout << color3[i][j] << ", ";
            //     cout << el;
            // }
            // RAYA;
            queue<iii> qq;
            qq.push(make_pair(make_pair(x1, y1), 1));
            vector<vi> vis(n, vi(m));
            bool cambiarColor = false;
            while (!qq.empty())
            {
                iii curr = qq.front();
                qq.pop();
                if (vis[curr.fi.fi][curr.fi.se])
                    continue;
                int x = curr.fi.fi, y = curr.fi.se;
                vis[x][y] = 1;
                bool color = curr.se;
                int clr = color ? 1 : 4;
                if (x == x2 && y == y2)
                    color3[x][y] = color3[x2][y2];
                else
                    color3[x][y] = clr;
                color = !color;
                clr = color ? 1 : 4;
                forn(i, 4)
                {
                    int dxx = dx[i], dyy = dy[i];
                    if (x + dxx >= n || x + dxx < 0 || y + dyy < 0 || y + dyy >= m)
                        continue;
                    if (vis[x + dxx][y + dyy])
                        continue;
                    if ((!vis[x + dxx][y + dyy]) && (color3[x + dxx][y + dyy] == 0 || color3[x + dxx][y + dyy] == clr))
                    {
                        qq.push(make_pair(make_pair(x + dxx, y + dyy), color));
                    }
                    else if (color3[x + dxx][y + dyy] != clr)
                    {
                        qq.push(make_pair(make_pair(x + dxx, y + dyy), color));
                    }
                }
            }
            forn(i, n)
            {
                forn(j, m) cout << color3[i][j] << " ";
                cout << el;
            }
        }
        else
            forn(i, n)
            {
                forn(j, m) cout << edges[i][j] << " ";
                cout << el;
            }
    }
}