

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
typedef vector<ll> vll;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

#define MIN 1900
const int MOD = 1e9 + 7;
const int MAXC = 1e3 + 3;
const int MAXR = 1e3 + 3;

ll dp[MAXR][MAXC];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vc> M(n, vc(m));

    forn(i, n)
    {
        string w;
        cin >> w;
        forn(j, m) M[i][j] = w[j];
    }
    bool noWall = true;
    ford(i, n)
    {
        if (M[i][m - 1] != '#' && noWall)
            dp[i][m - 1] = 1;
        if (M[i][m - 1] == '#')
            noWall = false;
    }
    noWall = true;
    ford(j, m)
    {
        if (M[n - 1][j] != '#' && noWall)
            dp[n - 1][j] = 1;
        if (M[n - 1][j] == '#')
            noWall = false;
    }

    ford(i, n - 1)
    {
        ford(j, m - 1)
        {
            if (M[i][j] != '#')
                dp[i][j] = (dp[i + 1][j] % MOD) + (dp[i][j + 1] % MOD);
        }
    }
    // forn(i, n)
    // {
    //     forn(j, m)
    //     {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << el;
    // }
    int val = dp[0][0] % MOD;
    cout << val << "\n";
}