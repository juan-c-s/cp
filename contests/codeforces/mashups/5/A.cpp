
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

void actualize(unordered_map<int, int> &posi, int &cont, int pos, int n)
{
    for (int j = pos - 2; j <= pos + 2; j++)
    {
        if (j >= 0 && j < n && posi[j])
        {
            cont--;
            posi[j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    string word;
    cin >> n >> q;
    cin >> word;
    int cont = 0;
    unordered_map<int, int> posi; //store if in x position, starts an abc
    for (int i = 0; i < n - 2; i++)
    {
        if (word.substr(i, 3) == "abc")
        {
            cont++;
            posi[i] = 1;
            i += 2;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int pos;
        char let;
        cin >> pos >> let;
        pos--;
        if (let == 'a')
        {
            if (!posi[pos])
            {
                actualize(posi, cont, pos, n);
                if (pos + 1 < n && pos + 2 < n && word[pos + 1] == 'b' && word[pos + 2] == 'c')
                {
                    cont++;
                    posi[pos] = 1;
                }
            }
            cout << cont << "\n";
        }
        else if (let == 'b')
        {
            if (!posi[pos - 1])
            {
                actualize(posi, cont, pos, n);
                if (pos - 1 >= 0 && pos + 1 < n && word[pos - 1] == 'a' && word[pos + 1] == 'c')
                {
                    cont++;
                    posi[pos - 1] = 1;
                }
            }

            cout << cont << "\n";
        }
        else if (let == 'c')
        {
            if (!posi[pos - 2])
            {
                actualize(posi, cont, pos, n);
                if (pos - 2 >= 0 && pos - 1 >= 0 && word[pos - 2] == 'a' && word[pos - 2] == 'b')
                {
                    cont++;
                    posi[pos - 2] = 1;
                }
            }
            cout << cont << "\n";
        }
    }
}
