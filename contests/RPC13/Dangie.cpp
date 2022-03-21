

#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <tuple>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
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

    //∑ i=1 hasta n-1
    //∑ j=i+1 hasta n
    //∑ k=1 hasta j
    int T;
    cin >> T;
    while (T--)
    {
        ll n, answer;
        cin >> n;
        answer = (((n - 1) * (n + 1) * n) / 2.0) - (((n - 1) * n * ((2 * n) - 1)) / 12.0) - ((3.0 * ((n - 1) * n)) / 4.0) - ((2.0 * (n - 1)) / 2.0);
        cout << answer << "\n";
    }
}