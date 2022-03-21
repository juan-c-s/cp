

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string.h>
#include <sstream>

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
#define MAX 2038
#define MIN 1900
ll turnsToWin(ll othershealth, ll damage)
{
    return (othershealth % damage == 0 ? othershealth / damage : othershealth / damage + 1);
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a; //hc =healthcharacter k = coins | w = weaponUpgrade | a = armor upgrade
        ll turnsForCWin = turnsToWin(hm, dc), turnsForMWin = turnsToWin(hc, dm);
        if (turnsForCWin <= turnsForMWin)
            cout << "YES\n";
        else
        {
            bool yessir = false;
            for (ll i = 0; i <= k; i++)
            {

                if (turnsToWin(hm, dc + i * w) <= turnsToWin(hc + (k - i) * a, dm))
                {
                    yessir = true;
                    break;
                }
            }
            if (yessir)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
//
//4 4
//1 7 5 2   bi
//2 6 5 2   ci
// 1 1 1 1 ai
//
//1 1 1 2    money += ci = 2 ; money = 2
//1 1 2 2
// 1 1 4 2
//1 7 5 2      a1=b1; a3=b3; a4=b4  ; money = 9
// 1 1 5 2
//
//
//
//
//
//
//
//
//
