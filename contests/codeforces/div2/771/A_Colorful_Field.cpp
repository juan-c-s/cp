
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string.h>
#include <sstream>
#include <bitset>

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
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vi f;
    forn(i, k)
    {
        int x, y;
        cin >> x >> y;
        x--;
        f.pb(x * m + y); //#of cell
    }

    sort(all(f));
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        ll pos = x * m + y;
        int ans = 0;
        bool waste = false;
        for (int i = 0; i < f.size(); i++)
        {
            if (f[i] < pos)
                ans++;
            else if (f[i] == pos)
            {
                waste = 1;
                break;
            }
            else
                break;
        }
        pos -= ans;
        pos %= 3;
        if (waste)
            cout << "Waste\n";
        else if (pos == 1)
            cout << "Carrots\n";
        else if (pos == 2)
            cout << "Kiwis\n";
        else
            cout << "Grapes\n";
    }
}
