

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

struct Pair
{
    int x, y;
    Pair(int x = 0, int y = 0) : x(x), y(y){};
    bool operator<(const Pair &right) const
    {
        if (right.x == x)
            return y > right.y;
        else
            return x < right.x;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<Pair> teams(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Pair szs(x, y);
        teams[i] = szs;
    }
    sort(teams.begin(), teams.end());
    int maxP = teams[n - 1].x, maxT = teams[n - 1].y, cont = 1, index = 1;

    vector<int> positions(n);
    positions[0] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int p = teams[i].x, t = teams[i].y;
        if (maxP == p && maxT == t)
        {
            positions[index++] = ++cont;
        }
        else
        {
            cont = 1;
            maxP = p;
            maxT = t;
            positions[index++] = cont;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (positions[i] > 0)
        {
            int adding = positions[i];
            for (int j = 0; j < positions[i] - 1; j++)
            {
                positions[--i] = adding;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        DBG(positions[i]);
    }
    cout << positions[k - 1] << "\n";
}