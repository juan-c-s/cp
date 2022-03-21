

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

int numFactoredBinaryTrees(vector<int> &arr)
{
    int MOD = 1e9 + 7;
    unordered_map<int, int> isInArray;
    unordered_map<long long, vector<pair<long long, long long> > > factors;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        isInArray[arr[i]] = i + 1;
        factors[arr[i]] = vector<pair<long long, long long> >();
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size() && (arr[i] * arr[j]) <= arr[arr.size() - 1]; j++)
        {
            int mult = (arr[i] * arr[j]);
            if (isInArray[mult])
            {
                factors[mult].push_back(pair<int, int>(arr[i], arr[j]));
                if (arr[i] != arr[j])
                    factors[mult].push_back(pair<int, int>(arr[j], arr[i]));
            }
        }
    }
    long long ans = 0;
    vector<long long> dp(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        int currAns = 1; //cada valor puede ser un árbol
        for (int j = 0; j < factors[arr[i]].size(); j++)
        {
            int index = isInArray[factors[arr[i]][j].first] - 1;
            int indexb = isInArray[factors[arr[i]][j].second] - 1;
            currAns = (currAns + (dp[index] * dp[indexb]) % MOD) % MOD;
        }
        dp[i] = currAns;
        ans = (ans + dp[i]) % MOD;
        // DBG(dp[i]);
    }
    return ans;
};

// 16
//4  4
// 16
//4     4
//2 2  2 2
//    16
//  4    4
// 2  2

//dp[i] = trees created with ith element
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int s = numFactoredBinaryTrees(v);
    DBG(s);
}
//4 = [1, 4,     5,      16,     17,        20,         21,            64]
// [4^0, 4^1, (4^0+4^1),(4^2),(4^2+4^0), (4^2+4^1), (4^2+4^1+4^0),(4^3),(4^3+4^0),(4^3+4^1),(4^3+4^1+4^0),(4^3+4^2),(4^3+4^2+4^1),(4^3+4^2+4^1+4^0)]

// 0 1,  1 0,   1 1