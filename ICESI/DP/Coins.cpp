

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
typedef pair<int, int> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<ll> vll;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

#define MIN 1900
const int MOD = 1e9 + 7;
const int MAX = 3e3 + 3;

double dp[MAX][2];

// double maximizing()

double maximizing(int i, bool head, int n, vd &v, int cantidad) // cantidad = cantidad de cabezas
{
    if (i == n)
    {
        if (cantidad < n / 2 + 1)
            return 0.0;
        return 1.0;
    }
    double &r = dp[i][head];
    if (r != 0)
        return r;
    double val = v[i];
    if (!head)
        val = 1.0 - v[i];
    double d1 = maximizing(i + 1, true, n, v, cantidad + 1) * val;
    double d2 = maximizing(i + 1, false, n, v, cantidad) * val;
    DBG(d1);
    DBG(d2);
    if (d1 != -1.0)
        r += d1;
    if (d2 != -1.0)
        r += d2;
    return r;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vd v(n);
    forn(i, n) cin >> v[i];

    memset(dp, 0, sizeof(dp));
    double ans1 = maximizing(0, 0, n, v, 0);
    double ans2 = maximizing(0, 1, n, v, 1);
    DBG(ans1 + ans2);
    forn(i, n)
    {
        forn(j, 2)
        {
            cout << dp[i][j] << ", ";
        }
        cout << el;
    }
}