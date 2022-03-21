#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v(n), sorted(n);
    unordered_map<int, int> maxDiff;
    forn(i, n)
    {
        cin >> v[i];
    }
    copy(all(v), sorted.begin());
    sort(all(sorted));
    int p2 = n - 1;
    for (int p1 = 0; p1 < n / 2; p1++)
    {
        maxDiff[sorted[p1]] = sorted[p2];
        maxDiff[sorted[p2]] = sorted[p1];
        p2--;
    }
    forn(i, n)
    {
        if (maxDiff[v[i]])
            v[i] = maxDiff[v[i]];
    }
    forn(i, n)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}