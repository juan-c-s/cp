

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
    int n, m; //m = groups | n = users
    cin >> n >> m;
    vector<vi> matrix(n);
    vi ans(n);
    vector<bool> visited(n);

    forn(i, m)
    {
        int k;
        cin >> k;
        vi groups(k);
        forn(j, k)
        {
            int num;
            cin >> num;
            groups[j] = num - 1;
        }
        for (int j = 0; j < k - 1; j++)
        {
            matrix[groups[j]].pb(groups[j + 1]);
            matrix[groups[j + 1]].pb(groups[j]);
        }
    }

    forn(k, n)
    {
        if (!visited[k])
        {
            vi components;

            queue<int> q;
            q.push(k);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                if (visited[curr]) //this if makes sure that if There is a node added to the queue, making sure that it wasn't visited while the other nodes were called
                    continue;
                components.pb(curr);
                visited[curr] = true;
                for (int i = 0; i < matrix[curr].size(); i++)
                    if (!visited[matrix[curr][i]])
                        q.push(matrix[curr][i]);
            }
            forn(i, components.size()) ans[components[i]] = components.size();
        }
    }
    forn(i, ans.size()) cout << ans[i] << " ";
    cout << "\n";
}
