#include <iostream>
#include <vector>
#include <unordered_map>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================" << endl
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

const int inf = 1e9 + 1;
const int nax = 1e5 + 200;

const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    int mn = 1e7, ans = -1;
    forn(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x >= t)
        {
            if (x - t < mn)
            {
                ans = i + 1;
                mn = x - t;
            }
        }
        else
        {
            double calc = (t - x) % y != 0 ? (((int)((double)(t - x) / y + 1)) * y + x) - t : 0;

            if (calc < mn)
            {
                ans = i + 1;
                mn = calc;
            }
        }
    }
    cout << ans << "\n";
}