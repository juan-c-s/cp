
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

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX
#define MIN 1900

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v(n);
    vector<ll> sum(n); //overall sum from left and overall sum from right
    forn(i, n)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            if (i >= 3)
            {
                sum[i] += v[i] + sum[i - 2];
            }
            else
                sum[i] = v[i];
        }
        else
        {
            if (i >= 2)
                sum[i] += v[i] + sum[i - 2];
            else
                sum[i] = v[i];
        }
    }
    int ans = 0;
    if (n == 1)
        cout << "1\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            ll pairSum, oddSum;
            pairSum = sum[n - 1];
            oddSum = sum[n - 2];
            if (((n - 1) & 1))
                swap(pairSum, oddSum);
            if (i & 1)
            {
                //lo que queda
                ll restoDelImparqueesPar = i - 1 >= 0 ? pairSum - sum[i - 1] : pairSum;
                ll restoDelParQueEsImpar = oddSum - sum[i];
                ll prefixImpar = (i - 2 >= 0) ? sum[i - 2] : 0;
                ll prefixPar = (i - 1 >= 0) ? sum[i - 1] : 0;
                if (1LL * restoDelImparqueesPar + prefixImpar == restoDelParQueEsImpar + prefixPar)
                    ans++;
            }
            else
            {
                ll restoDelParQueEsImpar = i - 1 >= 0 ? oddSum - sum[i - 1] : oddSum;
                ll restoDelImparqueesPar = pairSum - sum[i];
                ll prefixImpar = (i - 1 >= 0) ? sum[i - 1] : 0;
                ll prefixPar = (i - 2 >= 0) ? sum[i - 2] : 0;
                if (1LL * restoDelImparqueesPar + prefixImpar == restoDelParQueEsImpar + prefixPar)
                    ans++;
            }
        }
        cout << ans << "\n";
    }
}
