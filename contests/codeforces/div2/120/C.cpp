#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 1e9

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

//tomar t números que la suma sea <=k significa que no hay que tocar esos elementos
//buscar un x mínimo en el que multiplicando ese x a los n-t elementos para que sea <=k

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k, sum = 0, steps = 0;
        cin >> n >> k;
        int mn;
        priority_queue<int> maxx;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            mn = min(num, mn);
            maxx.push(num);
            sum += num;
        }
        if (n > 1)
            while (sum > k)
            {
                int mx = maxx.top();
                if (mx - mn > 1 && sum - (mx - mn) <= k)
                {
                    sum -= (mx - mn);
                    maxx.pop();
                    maxx.push(mn);
                }
                else
                {
                    mn--;
                    sum--;
                }
                steps++;
            }
        else
            steps = k > maxx.top() ? 0 : maxx.top() - k;
        cout << steps << "\n";
    }
}