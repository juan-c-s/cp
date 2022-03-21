

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e2 + 1 //MAX number is 50
#define MIN -1e7

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
vector<int> list;
vector<int> dp;
int sum(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return MIN;
    if (dp[n])
        return dp[n];
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (n - list[i] >= 0)
            ans = max(ans, sum(n - list[i]) + 1);
    }
    return ans == 0 ? dp[n] = MIN : dp[n] = ans; //no sumó nada
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    list.pb(a);

    list.pb(b);
    list.pb(c);
    dp.resize(n + 1);
    sort(list.begin(), list.end());
    int cont = sum(n);

    cout << dp[n] << "\n";
}