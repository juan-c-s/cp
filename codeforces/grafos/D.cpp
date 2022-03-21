

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>

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

vector<bool> colors;
vector<vi> m;
vi visited;
bool answer = true;
void dfs(int curr, bool color)
{
    if (visited[curr])
        return;
    visited[curr] = 1;
    colors[curr] = color;
    forn(i, m[curr].size())
    {
        if (!visited[m[curr][i]])
        {
            dfs(m[curr][i], color ^ 1);
        }
        else
        {
            if (color == colors[m[curr][i]])
            {
                answer = false;
            };
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;
    colors.resize(V);
    visited.resize(V);
    m.resize(V, vi());
    // forn(i, V) m[i].reserve(V); //so it doesn't reallocate items and waste time **This line works when have lots of memory** and need time
    forn(i, E)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        m[u].pb(v);
        m[v].pb(u);
    }
    forn(i, V) if (!visited[i]) dfs(i, 0);
    if (!answer)
        cout << "-1\n";
    else
    {
        int count[2] = {0};
        forn(i, V) count[colors[i]]++;
        cout << count[0] << "\n";
        forn(i, V) if (!colors[i]) cout << i + 1 << " ";
        cout << "\n";
        cout << count[1] << "\n";
        forn(i, V) if (colors[i]) cout << i + 1 << " ";
        cout << "\n";
    }
}
