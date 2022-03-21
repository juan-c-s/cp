

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
#include <string>
#include <map>

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

#define MAX 1e6
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;

const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    string word;
    cin >> n >> k >> word;
    map<char, int> m;

    for (int i = 0; i < n; i++)
    {
        m[word[i]]++;
    }
    ll cont = 0;
    // for (int i = 0; i < k; i++)
    // {
    //     cont += m[word[i]];
    // }
    //sortMap
    vector<pair<int, char> > let;
    for (map<char, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        let.pb(pair<int, char>(i->second, i->first));
    }

    sort(all(let));
    // ford(i, let.size())
    // {
    //     cout << "(" << let[i].second << ", " << let[i].first << "), ";
    // }

    // cout << "\n";
    // RAYA;
    ford(i, let.size())
    {
        // DBG(let[i].second);
        // DBG(let[i].first);
        // DBG(k);
        if (k == 0)
            break;
        if (let[i].first > k)
        {
            cont += 1LL * (k) * (k);
            k -= k;
        }
        else
        {
            cont += 1LL * let[i].first * let[i].first;
            k -= let[i].first;
        }
        // DBG(cont);
        // RAYA;
    }
    // for (map<char, int>::iterator i = m.begin(); i != m.end(); i++)
    // {
    //     if (k < 0)
    //         break;
    //     if (i->second >= k)
    //     {
    //         cont += k;
    //     }
    //     else
    //         cont += 1LL * i->second * i->second;
    //     k -= i->second;
    //     DBG(cont);
    // }
    cout << cont << "\n";
}