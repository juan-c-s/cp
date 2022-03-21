
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi v(MAX - MIN + 1);
    fore(i, MIN, MAX) if (i % 4 == 0) v[i - MIN] = 1;
    fore(i, MIN, MAX) if (i % 100 == 0) v[i - MIN] = 0;
    fore(i, MIN, MAX) if (i % 400 == 0) v[i - MIN] = 1;

    string date1, date2;
    getline(cin, date1);
    getline(cin, date2);
    if (date1 > date2)
        swap(date1, date2);
    stringstream d1(date1);
    stringstream d2(date2);
    vi dat1(3);
    int index = 0;
    while (d1.good())
    {
        string substr;
        getline(d1, substr, ':');
        dat1[index++] = stoi(substr);
    }
    vi dat2(3); //(0->año)(1->mes)(2->día)
    index = 0;
    while (d2.good())
    {
        string substr;
        getline(d2, substr, ':');
        dat2[index++] = stoi(substr);
    }
    int years = dat2[0] - dat1[0];
    int days = 0;
    int months = 0;

    if (dat2[1] >= dat1[1])
    {
        days = years * 365;
        for (int i = dat1[1]; i < dat2[1]; i++)
        {
            if (m[i - 1] == 1)
                days += 31;
            else if (!m[i - 1])
                days += 30;
            else if (m[i - 1] == -1)
                days += 28; //assuming all years will be leap(later I will add days for leap years)
        }
        days += (dat2[2] - dat1[2]);
        for (int i = dat1[0]; i < dat2[0]; i++)
        {
            if (v[i - MIN])
            {
                days++;
            }
        }
        if (v[dat2[0] - MIN] == 1 && (dat2[1] > 2 || (dat2[1] == 2 && dat2[2] == 29)))
            days++;

        cout << days << "\n";
    }
    else
    {
        days = years * 365;
        for (int i = dat2[1] - 1; i >= dat1[1]; i--)
        {
            if (m[i - 1] == 1)
                days -= 31;
            else if (!m[i - 1])
                days -= 30;
            else if (m[i - 1] == -1)
                days -= 28; //assuming all years will be leap(later I will add days for leap years)
        }
        days += (dat2[2] - dat1[2]);
        if (v[dat2[0] - MIN] == 1 && (dat2[1] > 2 || (dat2[1] == 2 && dat2[2] == 29)))
            days++;

        cout << days << "\n";
    }
}

//366 leap year days
