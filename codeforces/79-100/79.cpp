

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
    int N;
    cin >> N;
    vi a(N);
    vi b(N);
    string t;
    cin >> t;
    int ai = 0, bi = 0;
    for (int i = 0; i < N; i++)
    {
        a[ai++] = t[i] - '0';
    }

    for (int i = N; i < N * 2; i++)
    {
        b[bi++] = t[i] - '0';
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    // for (int i = 0; i < N; i++)
    // {
    //     DBG(b[i]);
    //     DBG(a[i]);
    // }
    bool flagMenor = true;
    bool flagMayor = true;

    for (int i = 0; i < N; i++)
    {
        if (a[i] >= b[i])
        {
            flagMenor = false;
        }
        if (a[i] <= b[i])
        {
            flagMayor = false;
        }
    }
    if (flagMenor || flagMayor)
        cout << "YES\n";
    else
        cout << "NO\n";
}