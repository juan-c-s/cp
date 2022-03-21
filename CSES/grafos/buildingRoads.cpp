
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>

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
vector<vi> m;
vi visited;
void make_set(int num)
{
    parent[num] = num;
    ranks[num] = 1;
}
int find(int num)
{
    int val = (parent[num] == num ? num : find(parent[num]));
    return parent[num] = val;
}
void join_set(int x, int y)
{
    int a = find(x), b = find(y);
    if (ranks[a] < ranks[b])
        swap(a, b);
    ranks[a] += ranks[b];
    parent[b] = a;
};
void dfs(int u)
{
    for (int i = 0; i < m[u].size(); i++)
    {
        if (!visited[m[u][i]])
            join_set(u, m[u][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e;
    cin >> n >> e;

    parent.resize(n);
    ranks.resize(n);
    m.resize(n, vi());
    visited.resize(n);

    forn(i, n)
        make_set(i);

    forn(i, e)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        m[u].push_back(v);
        join_set(u, v);
    }
    set<int> s;
    forn(i, n)
    {
        s.insert(find(i));
    }
    if (s.size() == 1)
        cout << 0 << "\n";
    else
    {
        int origin = *s.begin();
        set<int>::iterator i = s.begin();
        i++;
        vector<ii> roads;
        for (; i != s.end(); i++)
        {
            roads.pb(make_pair(origin, *i));
        }
        cout << roads.size() << "\n";
        forn(j, roads.size()) cout << roads[j].fi + 1 << " " << roads[j].se + 1 << "\n";
    }
}
