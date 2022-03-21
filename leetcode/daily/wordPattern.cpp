
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
#include <sstream>
#include <set>

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
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> um;
    stringstream ss(s);
    bool answer = true;
    for (int i = 0; i < pattern.size(); i++)
    {
        string word;
        ss >> word;
        if (um[pattern[i]] == "")
            um[pattern[i]] = word;
        else if (um[pattern[i]] != word)
        {
            answer = false;
            break;
        }
    }
    unordered_map<string, int> freq;
    for (unordered_map<char, string>::iterator itt = um.begin(); itt != um.end(); itt++)
    {
        if (freq[itt->second] == 1)
        {

            answer = false;
            break;
        }
        freq[itt->second] = 1;
    }

    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool ans = wordPattern("abba", "dog cat cat dog");
    cout << ans << "\n";
}