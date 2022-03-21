

#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

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
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        int n = log10(b);
        stack<ll> s;
        bool sepuede = true;
        for (int i = 0; i <= n; i++)
        {
            int a1 = a % 10, b1 = b % 10;
            if (a1 > b1)
            {
                b1 = b % 100;
                b /= 10;
                if (b % 10 != 1)
                    sepuede = false;
            }
            s.push(b1 - a1);

            a /= 10;
            b /= 10;
        }
        string c = "";
        while (!s.empty())
        {
            ll el = s.top();
            if (el < 0)
                sepuede = false;
            s.pop();
            c += to_string(el);
        }

        while (c[0] == '0')
            c.erase(c.begin());

        cout << (sepuede ? c : "-1") << "\n";
    }
}