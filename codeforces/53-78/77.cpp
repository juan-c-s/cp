

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

    int N;
    cin >> N;
    int cont = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cont += num;
    }
    if ((cont % N) == 0)
    {
        cout << N << "\n";
    }
    else
        cout << N - 1 << "\n";
}