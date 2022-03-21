

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

bool check(int curr, unordered_map<int, int> um)
{
    int total_sum = 0, sum1 = 0, sum2 = 0;
    for (unordered_map<int, int>::iterator it = um.begin(); it != um.end(); it++)
    {
        if (it->first == curr)
            sum1 = sum2 = it->first / 2 * it->second;
        total_sum += it->first * it->second;
    }
    if (total_sum % 2)
        return false;
    int target = total_sum / 2;
    // encontrar si se puede llegar al target
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v(n);
    unordered_map<int, int> um;
    forn(i, n)
    {
        cin >> v[i];
        um[v[i]]++;
    }
    int lo = 0, hi = 2e5;
    while (lo + 1 < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (um[mid] % 2)
            um[mid]--;
        if (check(mid, um))
        {
            hi = mid;
        }
        else
            lo = mid;
        um[mid]++;
    }
}

// 1 3 4 6
// 1 2 3 4 6
//
// 1 3 6 10 16
//
//
