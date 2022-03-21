

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string word;
        cin >> word;
        if (word.size() % 2 == 1)
            cout << "NO\n";
        else
        {
            if (word.substr(0, word.size() / 2) == word.substr(word.size() / 2))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}