
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
void dijkstra(int origen, vi &visited, vector<vector<ii> > &m, vector<ll> &dist)
{
    int n = dist.size();
    forn(i, n) dist[i] = 1e10;
    priority_queue<ii, vector<ii>, greater<ii> > pq; //pair<int,int> (distancia a ese nodo,nodo)
    dist[origen] = 0;

    pair<ll, ll> p(0, origen);
    pq.push(p);
    while (!pq.empty())
    {
        ii curr = pq.top();
        pq.pop();
        if (visited[curr.se])
            continue;
        visited[curr.se] = 1;
        int parent = curr.se;
        for (int i = 0; i < m[parent].size(); i++)
        {
            ll newDistance = m[parent][i].second + curr.fi;
            if (newDistance < dist[m[parent][i].first])
            {
                dist[m[parent][i].fi] = newDistance;
                ii p2(dist[m[parent][i].fi], m[parent][i].fi);
                pq.push(p2);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, k;
    cin >> n >> e >> k;
    vi a(n);
    vector<vector<ii> > m(n + 1);

    forn(i, n) cin >> a[i];
    forn(i, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        ii p(v, w), p2(u, w); //pair (destination,weight)
        m[u].pb(p);
        m[v].pb(p2);
    }
    forn(i, n)
    {
        ii p(n, a[i]), p2(i, a[i]);
        m[i].pb(p);
        m[n].pb(p2);
    }
    forn(i, k)
    {
        int bi;
        cin >> bi;
        bi--;
        vi visited(n + 1);
        vector<ll> dist(n + 1);
        dijkstra(bi, visited, m, dist);
        forn(j, n) cout << dist[j] << " ";
        cout << "\n";
    }
}
