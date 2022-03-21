
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
#define MAX 1e9
#define MIN 1900
#define MOD 1e9 + 1

void Kadane(vi &v, int &mxBegins, int &mxEnds, int &mx)
{
    int local = 0, begins = 0, ends = 0, n = v.size();
    forn(i, n)
    {
        if (local + v[i] < 0)
        {
            local = 0;
            ends = begins;
            begins = local;
        }
        else
            local += v[i];
        if (local > mx)
        {
            mxBegins = begins;
            ends = i;
            mxEnds = ends;
            mx = local;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi v(n);
        forn(i, n) cin >> v[i];
        forn(i, n) v[i] += x;
        int local = 0, mx = 0, begins = 0, ends = 0, mxBegins = 0, mxEnds = 0;
        Kadane(v, mxBegins, mxEnds, mx);

        int cont = 0;
        string ans = "";
        while (n - cont > mxEnds - mxBegins)
        {
            string c = to_string(mx);
            reverse(all(c));
            ans += " " + c;
            cont++;
        }
        while (mxBegins < mxEnds)
        {
            DBG(mxBegins);
            DBG(mxEnds);
            DBG(ans);
            int newMX = 0;

            if (v[mxBegins] < v[mxEnds])
            {
                v[mxBegins] -= x;
            }
            else
                v[mxEnds] -= x;
            Kadane(v, mxBegins, mxEnds, newMX);
            while (n - cont > mxEnds - mxBegins)
            {
                string c = to_string(newMX);
                reverse(all(c));
                ans += " " + c;
                cont++;
            }
            mx = newMX;
        }
        string c = to_string(v[mxBegins]);
        reverse(all(c));
        ans += " " + c;
        reverse(all(ans));
        DBG(ans);
        cout << ans << "\n";
    }
};
