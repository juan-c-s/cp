

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <stack>

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
typedef vector<ll> vll;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX

#define MIN 1900
const int MOD = 1e9 + 7;
const ll INF = 2e10 + 7;
ll sum(vector<ii> &v, int index, int weight)
{
    if (index >= v.size())
        return 0;
    if (weight < 0)
        return -INF;

    ll mx = -INF;
    fore(i, index, v.size())
    {
        mx = max(sum(v, index + 1, weight - v[i].se) + v[i].fi, mx);
        mx = max(mx, sum(v, index + 1, weight));
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> n >> W;
    vector<ii> v(n + 1);
    for1(i, n)
    {
        cin >> v[i].se >> v[i].fi;
    }
    sort(all(v));
    vector<vll> dp(2, vll(W + 1));
    for1(i, n)
    {
        for1(j, W)
        {
            if (j - v[i].se >= 0)
                dp[i & 1][j] = max(dp[(i + 1) & 1][j], dp[(i + 1) & 1][j - v[i].se] + v[i].fi);
            else
                dp[i & 1][j] = dp[(i + 1) & 1][j];
        }
    }
    cout << dp[n & 1][W] << "\n";
}