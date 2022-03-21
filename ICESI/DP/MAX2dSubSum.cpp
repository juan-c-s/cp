

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

int Kadane(vi &v)
{
    int global = -INF, local = 0;
    forn(i, v.size())
    {
        local += v[i];
        global = max(local, global);
        if (local < 0)
        {
            local = 0;
        }
    }
    return global;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vi> M(n, vi(n));
    forn(i, n) forn(j, n)
    {
        cin >> M[i][j];
        if (j > 0)
            M[i][j] += M[i][j - 1];
    }
    int maxSum = -1e9;

    // starting column
    forn(i, n)
    {
        // ending column
        fore(j, i, n - 1)
        {
            vi temp;
            forn(r, n)
            {
                int rowSum = 0;
                if (i > 0)
                {
                    rowSum += M[r][j] - M[r][i - 1];
                }
                else
                    rowSum += M[r][j];
                temp.pb(rowSum);
            }
            maxSum = max(maxSum, Kadane(temp));
        }
    }

    cout << maxSum << "\n";
}