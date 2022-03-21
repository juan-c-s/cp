

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

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX

#define MIN 1900
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

vi dp;
int minimizing(int n, vi &v)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
        return INF;
    if (dp[n] != -1)
        return dp[n];
    int ans = INF;
    forn(i, v.size())
        ans = min(ans, 1 + minimizing(n - v[i], v));
    return dp[n] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    dp.resize(x + 1, 0);
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    // int ans = minimizing(x, v);
    // if (ans == INF)
    //     ans = -1;
    // cout << ans << "\n";

    for (int i = 1; i <= x; i++)
    {
        // dp[i] = how many coins = 1 estado
        // transiciones = n
        int mn = INF;
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
            {
                mn = min(dp[i - v[j]] + 1, mn);
            }
        }
        dp[i] = mn;
    }
    if (dp[x] == INF)
        dp[x] = -1;
    cout << dp[x] << "\n";
}