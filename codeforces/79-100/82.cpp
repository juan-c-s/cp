

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e7 + 1 //MAX number is 1e6
#define MIN -1e7

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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        double a = pow(i, 2);
        for (int j = i; j < n; j++)
        {
            double b = pow(j, 2);
            if (sqrt(a + b) == (int)sqrt(a + b) && sqrt(a + b) <= n)
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}