

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
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
int m[] = {1, -1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
#define MAX
#define MIN 1900

bool dfs(vi &arr, int index, int num)
{
    if (index >= arr.size())
        return false;
    else if (index == num)
        return true;
    else
        return dfs(arr, index + arr[index], num);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    vi jumps(n);
    forn(i, n - 1) cin >> jumps[i];
    jumps[n - 1] = 1;

    bool ans = dfs(jumps, 0, t - 1);
    cout << (ans ? "YES" : "NO") << "\n";
}
//4 = [1, 4,     5,      16,     17,        20,         21,            64]
// [4^0, 4^1, (4^0+4^1),(4^2),(4^2+4^0), (4^2+4^1), (4^2+4^1+4^0),(4^3),(4^3+4^0),(4^3+4^1),(4^3+4^1+4^0),(4^3+4^2),(4^3+4^2+4^1),(4^3+4^2+4^1+4^0)]

// 0 1,  1 0,   1 1