

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    char biggest = 'B';
    char smallest = 'G';
    if (n < m)
        swap(biggest, smallest);
    int mx = max(m, n);
    int mn = min(m, n);
    vector<char> big(mx, biggest);
    vector<char> small(mn, smallest);
    string ans = "";
    int bgI = 0, smI = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (i & 1 && smI < mn)
            ans += small[smI++];
        else
            ans += big[bgI++];
    }
    cout << ans << "\n";
}