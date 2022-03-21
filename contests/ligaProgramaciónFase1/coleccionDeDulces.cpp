

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1
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
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, maxLocal = 0, maxGlobal = MIN;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            maxLocal = num + maxLocal;
            maxGlobal = max(maxGlobal, maxLocal);
            if (maxLocal < 0)
                maxLocal = 0;
        }
        cout << "Case #" << i + 1 << ": ";
        cout << maxGlobal << "\n";
    }
}