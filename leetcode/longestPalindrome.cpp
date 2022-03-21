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
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n));
    int maxLength = 1;
    pair<int, int> mx;

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i + 1 < n)
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                maxLength = 2;
                mx.first = i;
                mx.second = i + 1;
            }
            else
                dp[i][i + 1] = 0;
    }

    for (int x = 2; x < n; x++)
    {
        int i = 0;
        for (int j = x; j < n && i < n; j++)
        {
            if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                // DBG(i);
                // DBG(j);
                dp[i][j] = 1;
                if (j - i + 1 > maxLength)
                {
                    maxLength = j - i + 1;

                    mx.first = i;
                    mx.second = j;
                }
            }
            i++;
        }
    }
    // forn(i, n)
    // {
    //     fore(j, 0, n - 1)
    //     {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << "\n";
    // }
    return s.substr(mx.first, mx.second - mx.first + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s = longestPalindrome("babad");
    cout << s << "\n";
}