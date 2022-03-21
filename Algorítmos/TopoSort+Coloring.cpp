

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
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
int m[] = {1, -1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
#define MAX
#define MIN 1900

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vi> m(n);
    vi inGrad(n);
    string word;
    vi TopoSort;
    cin >> word;
    forn(i, k)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        m[u].pb(v);
        inGrad[v]++;
    }
    queue<int> q;
    forn(i, n) if (inGrad[i] == 0) q.push(i);
    int count = 0;
    while (!q.empty())
    {
        count++;
        int curr = q.front();
        q.pop();

        TopoSort.pb(curr);
        for (int i = 0; i < m[curr].size(); i++)
        {
            --inGrad[m[curr][i]];
            if (inGrad[m[curr][i]] == 0)
                q.push(m[curr][i]);
        }
    }
    // forn(i, TopoSort.size()) cout << TopoSort[i] << " ";
    // cout << "\n";
    // cout << "\n";
    if (count < n) //There is a cycle
        cout << "-1\n";
    else
    {
        int ans = 0;

        for (int i = 0; i < 26; i++) //all alfabet
        {
            char let = 'a' + i;
            vi dp(n, 0);
            forn(j, TopoSort.size())
            {
                if (word[TopoSort[j]] == let)
                    ++dp[TopoSort[j]];
                forn(k, m[TopoSort[j]].size()) dp[m[TopoSort[j]][k]] = max(dp[m[TopoSort[j]][k]], dp[TopoSort[j]]);
                ans = max(dp[TopoSort[j]], ans);
            }
        }
        cout << ans << "\n";
    }
}
