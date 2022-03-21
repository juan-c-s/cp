
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
        int n;
        cin >> n;
        vi v(n);

        forn(i, n) cin >> v[i];
        int ind = 1, l = 0, r = 0, mn = 600;
        bool flag1 = false;

        forn(i, n)
        {
            if (v[i] != ind++ && !flag1)
            {
                l = i;
                flag1 = true;
            }
            if (flag1 && l != i)
            {
                if (v[i] < mn)
                {
                    r = i;
                    mn = v[i];
                }
            }
        }
        if (n == 1)
            cout << v[0] << "\n";
        else if (flag1)
        {
            vi rev;
            for (int i = l; i < r + 1; i++)
            {
                rev.pb(v[i]);
            }

            reverse(all(rev));
            for (int i = 0; i < l; i++)
                cout << v[i] << " ";
            for (int i = 0; i < rev.size(); i++)
                cout << rev[i] << " ";
            for (int i = r + 1; i < n; i++)
                cout << v[i] << " ";
            cout << "\n";
        }
        else
        {
            forn(i, n) cout << v[i] << " ";
            cout << "\n";
        }
        // string s1 = w.substr(0, l);
        // string s2 = w.substr(l, w.size() - r);
        // cout << s1 + s2 << "\n";
    }
}
