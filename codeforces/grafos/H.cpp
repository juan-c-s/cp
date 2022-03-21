
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>

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
typedef pair<ll, ll> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX
#define MIN 1900
vi parent;
vi ranks;

void make_set(int val)
{
    parent[val] = val;
    ranks[val] = 1;
}
int find(int x)
{
    int val = (parent[x] == x ? x : find(parent[x]));
    return parent[x] = val;
}
void union_set(int x, int y)
{
    if (x == y)
        return;
    int a = find(x), b = find(y);
    if (ranks[a] < ranks[b])
        swap(a, b);
    ranks[a] += ranks[b];
    parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, k;
    cin >> n >> e >> k;
    parent.resize(n);
    ranks.resize(n);
    vector<iii> edges(e);
    vector<vector<ii> > kruskal(n); //iindex = u;vector< pair(v,w)>
    vi specialEdges(k);
    forn(i, k)
    {
        int num;
        cin >> num;
        num--;
        specialEdges[i] = num;
    }
    forn(i, n) make_set(i);
    forn(i, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        ii p(w, u); //pair (weight,origen)
        iii E1(p, v);

        edges[i] = E1;
    }
    sort(all(edges));
    // forn(i, edges.size())
    // {
    //     cout << "(u: " << edges[i].fi.se << "-> v: " << edges[i].se << ", w: " << edges[i].fi.fi << "), ";
    // }
    // cout << "\n";
    forn(i, edges.size())
    {
        int x = find(edges[i].fi.se), y = find(edges[i].se);
        if (x != y)
        {
            union_set(x, y);
            int u = edges[i].fi.se, v = edges[i].se, w = edges[i].fi.fi;
            ii p1(v, w);
            ii p2(u, w);
            kruskal[u].pb(p1);
            kruskal[v].pb(p2);
        }
    }
    // forn(i, parent.size()) cout << "(" << i << ": " << find(i) << "), ";
    // cout << "\n";

    forn(i, kruskal.size())
    {

        forn(j, kruskal[i].size())
        {
            cout << "(u: " << i << "-> v: " << kruskal[i][j].fi << ", w: " << kruskal[i][j].se << "), ";
        }
        cout << "\n";
    }
    cout << "\n";
    //TODO:: HAcer BFS desde el nodo y cojer la arista más grande que se encuentre
    forn(i, k)
    {
        vi visited(n);
        queue<int> q;
        q.push(specialEdges[i]);
        int mxNum = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (visited[front])
                continue;
            forn(j, kruskal[front].size())
            {
                if (!visited[kruskal[front][j]])
                {
                }
            }
        }
    }
}
