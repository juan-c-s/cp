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
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool greater(int a, int b)
{

    if (a > b)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi v1(n), v2(n);

        for (auto &x : v1)
            cin >> x;
        for (auto &x : v2)
            cin >> x;

        sort(all(v1), [](int a, int b)
             { return a > b; });
        sort(all(v2), [](int a, int b)
             { return a > b; });

        int indexv1 = n - (n / 4) - 1;
        int indexv2 = indexv1;

        for1(i, n - 1)
        {
            v1[i] = v1[i - 1] + v1[i];
            v2[i] = v2[i - 1] + v2[i];
        }

        if (v1[indexv1] >= v2[indexv2])
        {
            cout << 0 << el;
        }
        else
        {
            int newStages = 0;
            int contV1 = 0;
            int v2End = n - 1;

            while (true)
            {

                if (v1[indexv1] + contV1 >= v2[indexv2])
                    break;
                n++;
                newStages++, contV1 += 100;

                if (indexv2 == v2End)
                    indexv2++;
                if ((n - (n / 4) - 1) < indexv1)
                {
                    indexv1 = n - (n / 4) - 1;
                }
            }

            cout << newStages << el;
        }
    }

    return 0;
}