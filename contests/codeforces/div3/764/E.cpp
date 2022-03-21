
//thanks to @sharmaharisam videos
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <string>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<string, vi> substrings;
        for (int i = 1; i <= n; i++)
        {
            string w;
            cin >> w;
            for (int j = 0; j <= m - 2; j++)
            {
                vi two, three;
                two.pb(j + 1);
                two.pb(j + 2);
                two.pb(i);
                substrings[w.substr(j, 2)] = two;
                if (j < m - 2)
                {
                    three.pb(j + 1); //pos(0,2) but for answer (1,3)
                    three.pb(j + 3);
                    three.pb(i);
                    substrings[w.substr(j, 3)] = three;
                }
            }
        }
        string telefone;
        cin >> telefone;
        vector<int> dp(m);    //m numbers per telefone
        vector<vi> parent(m); //this list is to know how many positions to go back
        //do base cases when searching for substr(0,2)&&substr(0,3)

        if (m == 1)
        {
            cout << "-1\n";
            continue;
        }
        if (m > 1 && substrings.find(telefone.substr(0, 2)) != substrings.end())
        {
            dp[1] = 1;
            parent[1] = substrings[telefone.substr(0, 2)];
            parent[1].pb(2);
        }
        if (m > 2 && substrings.find(telefone.substr(0, 3)) != substrings.end())
        {
            dp[2] = 1;
            parent[2] = substrings[telefone.substr(0, 3)];
            parent[2].pb(3);
        }
        for (int i = 3; i < m; i++)
        {
            if (dp[i - 2] && substrings.find(telefone.substr(i - 1, 2)) != substrings.end())
            {
                dp[i] = 1;
                parent[i] = substrings[telefone.substr(i - 1, 2)];
                parent[i].pb(2);
            }
            if (dp[i - 3] && substrings.find(telefone.substr(i - 2, 3)) != substrings.end())
            {
                dp[i] = 1;
                parent[i] = substrings[telefone.substr(i - 2, 3)];
                parent[i].pb(3);
            }
        }
        if (!dp[m - 1])
            cout << "-1\n";
        else
        {
            ll curr = m - 1;
            vector<vi> ans;
            while (curr >= 0)
            {
                ans.pb(parent[curr]);
                curr -= parent[curr][3];
            }

            reverse(all(ans));
            cout << sz(ans) << "\n";
            for (int i = 0; i < sz(ans); i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
}