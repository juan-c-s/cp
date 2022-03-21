
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

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX
#define MIN 1900
#define MOD 1e9 + 1

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
        vl v(n);
        vector<ii> peaks;
        unordered_map<int, int> um;
        forn(i, n) cin >> v[i];
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i - 1] < v[i] && v[i + 1] < v[i])
            {
                peaks.pb(make_pair(i, v[i]));
                um[i] = 1;
            }
        }
        if (peaks.size() == 0)
        {
            cout << "0\n";
            forn(i, n) cout << v[i] << " ";
            cout << "\n";
        }
        else if (peaks.size() == 1)
        {
            cout << 1 << "\n";
            forn(i, n)
            {
                if (um[i])
                    v[i + 1] = v[i];

                cout << v[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            int cont = 0;
            forn(i, peaks.size())
            {
                if (peaks[i].fi == -1)
                    continue;
                ii curr = peaks[i];

                if (i + 1 < peaks.size())
                {
                    if (peaks[i + 1].fi - curr.fi == 2)
                    {
                        peaks[i + 1].fi = -1;
                        v[curr.fi + 1] = max(curr.second, peaks[i + 1].second);
                    }
                    else
                        v[curr.fi + 1] = curr.se;
                }
                else
                {
                    v[curr.fi + 1] = curr.second;
                    // DBG(curr.fi);
                }
                cont++;
            }
            cout << cont << "\n";
            forn(i, n) cout << v[i] << " ";
            cout << "\n";
        }
    }
}
