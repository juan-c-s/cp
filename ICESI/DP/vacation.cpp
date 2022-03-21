

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

#define MIN 1900
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 3;
int dp[MAX][3];
int maxGain(vector<vi> &m, int index, int prev, vector<vi> &dp)
{
    if (index == m.size())
        return 0;
    int mx = -1;

    if (prev != -1 && dp[index][prev] != -1)
    {
        return dp[index][prev];
    }
    forn(i, 3)
    {
        if (i == prev)
            continue;
        mx = max(maxGain(m, index + 1, i, dp) + m[index][i], mx);
    }
    return dp[index][prev] = mx;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vi> v(n, vi(3));
    forn(i, n) forn(j, 3) cin >> v[i][j];
    vector<vi> dp(n, vi(3, -1));
    int ans = maxGain(v, 0, -1, dp);
    // forn(i, n)
    // {
    //     forn(j, 3) cout << dp[i][j] << ", ";
    //     cout << "\n";
    // }
    cout << ans << el;
}