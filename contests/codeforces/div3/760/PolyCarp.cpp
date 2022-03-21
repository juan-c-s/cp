

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>

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
        vector<int> arr(7);
        for (int i = 0; i < 7; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        // DBG(perm.size());
        // DBG(perm[0].size());
        int a = arr[0], b = arr[1], c = arr[2], d = arr[3];
        if (a + b == c)
            cout << a << " " << b << " " << d << "\n";
        else
            cout << a << " " << b << " " << c << "\n";
    }
}