

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    unordered_map<int, pair<int, int> > um; //key,prevIndex
    unordered_map<int, vector<pair<int, int> > > pos;

    for (int i = 0; i < 2 * n; i++)
    {
        int num;
        cin >> num;

        um[num].first++;
        if (um[num].first % 2 == 0 && i != 0)
        {
            pos[num].push_back(pair<int, int>(um[num].second, i));
            continue;
        }
        else
            um[num].second = i;
    }
    bool sepuede = true;
    for (unordered_map<int, pair<int, int> >::iterator i = um.begin(); i != um.end(); i++)
    {
        if (i->second.first % 2 != 0)
            sepuede = false;
    }
    if (!sepuede)
        cout << "-1\n";
    else
        for (unordered_map<int, vector<pair<int, int> > >::iterator i = pos.begin(); i != pos.end(); i++)
        {
            for (int j = 0; j < i->second.size(); j++)
            {
                cout << i->second[j].first + 1 << " " << i->second[j].second + 1 << "\n";
            }
        }
}