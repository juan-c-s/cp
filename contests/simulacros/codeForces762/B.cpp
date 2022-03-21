

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e9 //MAX number is 1e9 +1
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
    ll nums = sqrt(MAX), cont = 0;

    map<ll, ll> numbers;
    unordered_map<ll, ll> answer;
    for (ll i = 2; i <= MAX; i++)
    {
        if (i * i > MAX)
            break;
        numbers[i * i] = i * i;
        if (i * i * i <= MAX)
            numbers[i * i * i] = i * i * i;
    }
    numbers[1] = 1;
    map<ll, ll>::iterator prev = numbers.begin();
    for (map<ll, ll>::iterator i = numbers.begin(); i != numbers.end(); i++)
    {
        // DBG(i->first);
        // RAYA;
        if (i != numbers.begin())
        {
            // DBG(answer[prev->first]);
            // DBG(prev->first);
            // RAYA;
            answer[i->first] = answer[prev->first] + 1;
            prev++;
        }
        else
            answer[i->first] = 1;
    }

    while (t--)
    {
        ll num;
        cin >> num;
        ll square = sqrt(num), cube = cbrt(num);
        ll mx = max(square * square, cube * cube * cube);

        cout << answer[mx] << "\n";
    }
    // cout << sqrt(MAX) << endl;
}