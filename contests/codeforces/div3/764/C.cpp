// 3 options
//   1)multiplying the first number so it follows sucesion
//   2) multiplying second number so it fits in the middle of the aritmetic progression
//   3) multiplying third number to fit progression
//   4) Not possible
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
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
        int n;
        cin >> n;
        vi v;
        unordered_map<int, int> um; //saving the el that are already from 1 to n
        forn(i, n)
        {
            int num;
            cin >> num;
            if (!um[num] && num <= n)
                um[num] = 1;
            else
                v.pb(num);
        }
        bool sepuede = true;
        // forn(i, v.size())
        // {
        //     cout << v[i] << ", ";
        // }
        // cout << "\n";
        forn(i, v.size())
        {
            int num = v[i];
            while (um[num] || num > n)
            {
                num /= 2;
            }
            if (num == 0)
            {
                sepuede = false;
                break;
            }
            else
            {
                um[num]++;
            }
        }
        // for (unordered_map<int, int>::iterator i = um.begin(); i != um.end(); i++)
        // {
        //     cout << "(" << i->first << "," << i->second << "), ";
        // }
        // cout << "\n";

        for1(i, n)
        {
            if (!um[i])
                sepuede = false;
        }
        cout << (sepuede ? "YES\n" : "NO\n");
    }
}