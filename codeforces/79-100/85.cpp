

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
    unordered_map<int, int> um;
    bool sepuede = true;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        um[num]++;
        if (num == 25)
            continue;
        if (num == 50)
        {
            if (um[25] >= 1)
                um[25]--;
            else
                sepuede = false;
        }
        else //100 devuelve 75
        {
            if (um[25] >= 1 && um[50] >= 1)
            {
                um[25]--;
                um[50]--;
            }
            else if (um[25] >= 3)
            {
                um[25] -= 3;
            }
            else
            {
                sepuede = false;
            }
        }
    }
    cout << (sepuede ? "YES" : "NO") << "\n";
}