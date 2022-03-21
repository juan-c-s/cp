
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string.h>
#include <sstream>

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
int m[] = {1, -1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
#define MAX 2038
#define MIN 1900
vi parent;
vi ranks;
vector<vi> matrix;
vi nEdges;

void make_set(int v)
{
    parent[v] = v;
    ranks[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    matrix[a].pb(b);
    matrix[b].pb(a);
    a = find_set(a);
    b = find_set(b);
    nEdges[a]++;
    if (a == b)
        return;

    if (ranks[a] < ranks[b])
        swap(a, b);

    parent[b] = a;
    ranks[a] += ranks[b];
    nEdges[a] += nEdges[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n);
        forn(i, n) cin >> v[i];
        int maxLocal = 0, prev = 0, comp = 0;
        bool una = false;
        forn(i, n)
        {
            if (v[i] > maxLocal)
            {
                comp++;
                prev = maxLocal;
                maxLocal = v[i];
                una = false;
            }
            else if (v[i] < prev && prev != 0 && !una)
            {
                comp--;
                una = true;
            }
        }
        cout << comp << "\n";
    }
}
