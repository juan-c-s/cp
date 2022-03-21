

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<ll> v(n);
    cin >> v[0];
    int firstP = 0, e = 0, s = -1;
    ll currSum = 0, cont = 0, mxP = 0;

    if ((v[0] < 0 && abs(v[0]) <= t))
    {
        s = 0;
        currSum += abs(v[0]);
        mxP = max(mxP, v[0]);
    }

    forn(i, n - 1)
    {
        cin >> v[i + 1];
        if (v[i + 1] <= t)
            mxP = max(mxP, v[i + 1]);
        if (s == -1 && v[i + 1] < 0 && abs(v[i + 1]) <= t)
        {
            s = i + 1;
            currSum = abs(v[i + 1]);
        }
        if (v[i] < 0 && v[i + 1 >= 0])
            firstP = i + 1;
    }

    //si s == -1 significa que no hay negativos
    ll mx = 0;
    cont = firstP; //sería las posiciones qeu se cogieron
    mx = max(mx, cont);
    currSum *= 2;
    e = firstP;
    if (currSum <= t)
    { //hacer el caso base que sería cojer los positivos que se pueda despues de pasar por los negativos
        for (int i = firstP; i < n && currSum + i <= t; i++)
        {
            currSum += v[i];
            cont++;
            e = i + 1;
        }
        mx = max(mx, cont);
    }

    if (e == n)
        cout << mx << "\n";
    else
    {

        while (s + 1 != n && e < n)
        {

            // DBG(e);
            // DBG(mx);

            // DBG(currSum);
            cont--;
            int prev = v[s++];
            if (prev < 0 && v[s] <= 0)
                currSum -= (v[s] - prev) * 2;
            else if (prev < 0 && v[s] > 0)
            {
                currSum = (v[s]);
                mx = max(mxP, mx);

                break;
            }
            // DBG(currSum);
            // RAYA;
            // DBG(e);
            while (currSum + v[e] <= t)
            {
                currSum += v[e];
                cont++;
                e++;
            }
            mx = max(cont, mx);
        }
        cout << mx << "\n";
    }
}
