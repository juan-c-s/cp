

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>

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
    cin >> n; //cantidad dominoes
    vi up(n);
    vi low(n);
    int lowSum = 0, upSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> up[i] >> low[i];
        upSum += up[i];
        lowSum += low[i];
    }

    bool canSwap = false;
    for (int i = 0; i < n; i++)
    {
        if (((low[i] % 2 == 0) && (up[i] % 2 == 1)) || ((low[i] % 2 == 1) && (up[i] % 2 == 0)))
        {
            canSwap = true;
        }
    }

    if (canSwap && n != 1)
    {
        if (lowSum % 2 == 1 && upSum % 2 == 1)
        {
            cout << "1\n";
        }
        else if (lowSum % 2 == 1 || upSum % 2 == 1)
        {
            cout << "-1\n";
        }
        else
            cout << "0\n";
    }
    else
    {
        if (lowSum % 2 == 1 || upSum % 2 == 1)
        {
            cout << "-1\n";
        }
        else
            cout << "0\n";
    }
}