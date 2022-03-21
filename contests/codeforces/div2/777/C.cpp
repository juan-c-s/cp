
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string.h>
#include <sstream>

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
#define MAX 2038
#define MIN 1900

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> mat(n, vi(m));
        forn(i, n)
        {
            string w;
            cin >> w;
            forn(j, m)
            {
                mat[i][j] = w[j] - '0';
            }
        }
        vector<pair<ii, ii> > ans;
        bool posible = true;
        ford(i, n)
        {
            ford(j, m)
            {
                if (mat[i][j])
                {
                    if (i == 0 && j == 0)
                    {
                        posible = false;
                        break;
                    }
                    if (i > 0)
                    {
                        ans.pb(make_pair(make_pair(i, j + 1), make_pair(i + 1, j + 1)));
                    }
                    else if (j > 0)
                    {
                        ans.pb(make_pair(make_pair(i + 1, j), make_pair(i + 1, j + 1)));
                    }
                }
            }
        }
        if (posible)
        {

            cout << ans.size() << "\n";
            forn(i, ans.size())
            {
                cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << "\n";
            }
        }
        else
            cout << "-1\n";
    }
}
