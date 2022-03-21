

#include <iostream>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>
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

        multiset<int> extraNumbers;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (um[num] >= 1)
                extraNumbers.insert(num);
            um[num]++;
        }
        ///MEXES
        vector<ll> dp(n + 1, 0);
        bool hasToIncrease = false;
        dp[0] = um[0];
        if (dp[0] == 0)
            hasToIncrease = true;

        //2 subproblemas
        //sumarle uno a todos los numeros que sean iguales al MEX
        //Asegurarse que el siempre haya numeros en los menores al MEX actual
        for1(i, n)
        {
            if (dp[i - 1] == -1)
            {
                dp[i] = -1;
                continue;
            }
            dp[i] += 1LL * (dp[i - 1] - um[i - 1]); //Añade operaciones para tener los menores
            // para que los menores a dp[i-1] tengan valor

            dp[i] += (1LL * um[i]); //Añade frecuencia del mismo número
            if (hasToIncrease)
            {
                multiset<int>::iterator itt = extraNumbers.upper_bound(i - 1); //same as lower_bound now that there i-1 is not supposed to be in the list

                if (itt == extraNumbers.begin())
                {
                    dp[i] = -1;
                    continue;
                }
                itt--; //Iterator was in i-1 but we want the closest to i-1
                dp[i] += 1LL * (i - 1 - *itt);
                // um[*itt]--; Dont need these because already traversed
                // um[i]++;
                extraNumbers.erase(itt);
                hasToIncrease = false;
            }
            if (!um[i])
                hasToIncrease = true;
            // DBG(dp[i]);
        }

        forn(i, n + 1) cout << dp[i] << " ";
        cout << "\n";
    }
}