#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <cmath>
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
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll product(ll n)
{
    int m = log10(n), product = 1;
    for (int i = 0; i <= m; i++)
    {
        product *= 1LL * (n % 10);
        n /= 10;
    }
    return product;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    if (n % 10 == 0)
        --n;
    for (int i = 0; i < log10(n); i++)
    {
    }

    ll m = n - (n % (ll)pow(10, (ll)log10(n))) - 1;
    cout << max(product(n), product(m)) << "\n";
}

//4 4 5 5 7 7
//4 4 4 5 5 7 7