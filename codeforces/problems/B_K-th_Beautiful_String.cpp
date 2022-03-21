
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>

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
typedef pair<ll, ll> ii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX
#define MIN 1900

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll left = 0, right = (n * (n - 1)) / 2;

        while (left + 1 < right)
        {
            ll mid = left + (right - left) / 2;
            if ((mid * (mid - 1)) / 2 <= k)
            {
                left = mid;
            }
            else
                right = mid;
        }
        // left == i
        string s;
        s.resize(n);
        forn(i, n) s[i] = 'a';
        int index = n - 1;
        ll start = (left * (left - 1)) / 2 + 1;

        if ((left * (left - 1)) / 2 == k)
        {
            left--;
            start = k;
            s[n - left] = 'b'; // now that it places the last b after the first b
        }
        else
            s[n - 1] = 'b'; // this is simply to start from left*(left-1)/2 + 1 which is the current kth string and the idea
        // is to move the b to the right until start == k

        s[n - 1 - left] = 'b';

        while (start < k && index >= 0)
        {
            start++;
            s[index--] = 'a';
            s[index] = 'b';
        }
        cout << s << "\n";
    }
    // encontrar i(i-1)/2 mas grande que sea menor a k
    //  se empieza en el i(i-1)/2 con la primera b en la posición i+1 del string y empezar a iterar con la segunda b en la pos n-1 del string
}
