

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
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

    int y, k, n;
    cin >> y >> k >> n;
    int xMax = n - y, first = k > y ? k : ((y / k) + 1) * k;
    if (y == n || first - y > xMax)
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = first - y; i <= xMax; i += k)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}