

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
#include <string>
#include <unordered_map>
#include <iterator>
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

    string w1, w2, fin;
    cin >> w1 >> w2 >> fin;
    unordered_map<char, int> um;
    for (int i = 0; i < fin.size(); i++)
    {
        um[fin[i]]++;
    }
    for (int i = 0; i < w1.size(); i++)
    {
        um[w1[i]]--;
    }
    for (int i = 0; i < w2.size(); i++)
    {
        um[w2[i]]--;
    }
    bool sepuede = true;
    for (unordered_map<char, int>::iterator i = um.begin(); i != um.end(); i++)
    {
        if (i->second != 0)
            sepuede = false;
    }

    if (sepuede)
        cout << "YES\n";
    else
        cout << "NO\n";
}