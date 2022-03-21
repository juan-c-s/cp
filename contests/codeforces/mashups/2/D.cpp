#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, mx = 0;
    cin >> n;
    vi v(n);
    unordered_map<int, int> um;
    forn(i, n)
    {
        cin >> v[i];
        mx = max(v[i], mx);
        um[v[i]]++;
    }
    bool sepuede = false;

    for (unordered_map<int, int>::iterator it = um.begin(); it != um.end(); it++)
    {
    }
    ford(i, n)
    {
        if (um[v[i]] & 1)
        {
            sepuede = true;
            break;
        }
    }
    if (!sepuede)
        cout << "Agasa\n";
    else
        cout << "Conan\n";
}

// 1 1 1 2 2 3 3
//2 2 3 3 4 4 5 56

//1 1 2 2 3 3
//1 0 1 0 1 0 1 0