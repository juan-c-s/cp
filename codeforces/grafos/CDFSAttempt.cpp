

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
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

int users = 0;
vi ans;

void dfs(vector<bool> &visited, vector<vi> &m, vector<vi> &groups, int curr)
{
    if (visited[curr])
        return;
    users++;
    visited[curr] = true;
    forn(i, m[curr].size())
    {
        int group_i = m[curr][i];
        forn(j, groups[group_i].size())
        {
            if (!visited[groups[group_i][j]])
                dfs(visited, m, groups, groups[group_i][j]);
        }
    }
    ans[curr] = users;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; //m = groups | n = users
    cin >> n >> m;
    vector<vi> matrix(n);
    vector<vi> groups(m);
    vector<bool> visited(n);
    ans.resize(n);
    forn(i, m)
    {
        int k;
        cin >> k;
        groups[i].resize(k);
        forn(j, k)
        {
            int num;
            cin >> num;
            groups[i][j] = --num;
            matrix[num].pb(i);
        }
    }
    forn(i, n)
    {
        users = 0;
        if (!visited[i])
        {
            dfs(visited, matrix, groups, i);
            cout << ans[i] << " ";
        }
        else
            cout << ans[i] << " ";
    }
    cout << "\n";
}
