

#include <iostream>
#include <algorithm>
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

    int N, M;
    cin >> N >> M;
    vi corr(N);
    vi wr(M);
    for (int i = 0; i < N; i++)
    {
        cin >> corr[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> wr[i];
    }
    sort(corr.begin(), corr.end());
    sort(wr.begin(), wr.end());
    if ((corr[0] * 2) <= wr[0] - 1 && (wr[0] > corr[N - 1]))
    {
        cout << max(corr[0] * 2, corr[N - 1]) << "\n";
    }
    else
        cout << "-1\n";
}