

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
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

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> um, pos;
    int cont = 0, mx = 0;

    for (int i = 0; i < s.size(); i++)
    {
        DBG(um[s[i]]);
        if (um[s[i]] > 0)
        {

            cont -= um[s[i]];

            for (int j = 0; j <= pos[s[i]]; j++)
            {
                um[s[j]] = 0;
                // DBG(s[j]);
            }
        }
        cont++;
        DBG(cont);
        DBG(i);
        RAYA;
        mx = max(cont, mx);
        um[s[i]] = cont;
        pos[s[i]] = i;
    }
    return mx;
}
int maxDistToClosest(vector<int> &seats)
{
    int cont = 0, mx = 0;
    bool unoAntes = false;
    if (seats[0] == 1)
        unoAntes = true;
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i] == 0)
            cont++;
        else if (unoAntes)
        {
            mx = max(cont, mx);
            unoAntes = false;
        }
        else
            mx = max((cont + 1) / 2, mx);
    }

    if (seats[seats.size() - 1] == 0)
        mx = max(cont, mx);
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << lengthOfLongestSubstring("bpfbhmipx") << "\n";
}