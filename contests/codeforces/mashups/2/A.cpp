#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
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
        int a, b, c, m;
        cin >> a >> b >> c >> m;
    }
}

//AAAAAA -> A = 6  (AA,AA,AA)=3 o (AAAAAA)=5 o (AAAA, AA)=4 o (A,A,A,A,A,A)=0 o (AA,A,A,A,A)=1 o (AAA,A,A,A)=2 o (AA,AA,A,A)=2(
//DDDDD -> D=5   (DDDDD)=4 o (DDDD,D)=3 o (DD,DD,D)=2 o (DDD,D,D)=2 o (DD,D,D,D)=1 o (D,D,D,D,D)=0
//CCCC -> C=4 (CCCC)=>3 o (CCC,C)=2 o (CC,CC)=2 o (CC,C,C)=1 o (C,C,C,C)=0
//BBB -> B=3  (BBB)=2 o (BB,B)=1

//4 4 0 0
//ABABABAB
//DD DD DD = 3 < menos parejas que DDDDDD=5

// 2 casos
// 1) cuando hay que maximizar parejas
// 2) cuando hay que minimizar parejas