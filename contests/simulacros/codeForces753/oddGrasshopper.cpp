

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        ll initial, n; //n = number of jumps
        cin >> initial >> n;
        ll from = (n / 4) * 4, ans = 0;

        for (ll i = from + 1; i <= n; i++)
        {
            if (initial & 1)
            {
                initial += i;
            }
            else
                initial -= i;
        }

        cout << initial << "\n";
    }
}