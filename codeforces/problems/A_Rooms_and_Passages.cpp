#include <iostream>
#include <vector>
#include <unordered_map>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================" << endl
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

const int inf = 1e9 + 1;
const int nax = 1e5 + 200;

const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vi dp(n);
    unordered_map<int, int> um;
    vi v(n);
    bool acabo = false;
    forn(i, n)
    {
        cin >> v[i];
        um[abs(v[i])] = 1;
    }
    int s = 0, i = 0;
    while (s < n)
    {
        if (i == n)
        {
            if (acabo)
                dp[s] = dp[s - 1] - 1;
            acabo = true;
            cout << dp[s] << " ";
            s++;
            continue;
        }
        if (v[i] > 0)
        {
            // DBG(v[i]);
            if (um[v[i]] == -1)
            {
                // DBG(i);
                // DBG(um[v[i]]);
                // DBG(v[i]);
                // DBG('p');
                s++;
                um[abs(v[s - 1])] = 1;
                if (s < n)
                {
                    if (v[s] < 0)
                        um[abs(v[s])] = -1;
                    dp[s] = dp[s - 1] - 1;
                    cout << dp[s - 1] << " ";
                    // DBG(dp[s]);
                }
                continue;
            }
            else
                dp[s]++;
        }
        else
        {

            um[abs(v[i])] = -1;
            dp[s]++;
        }
        i++;
    }
    cout << "\n";
    return 0;
}