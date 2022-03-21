

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <math.h>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1

using namespace std;

typedef long long ll;
typedef vector<int> vi;

//estados (peso,i)
//transiciones =>

//W = peso; wt = lista pesos ; val = lista valor del item ; n = elementos
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int> > dp(W + 1, vector<int>(2));
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= W; i++)
        {
            if (wt[j] > i)
            {
                dp[i][j & 1] = j - 1 >= 0 ? dp[i][(j + 1) & 1] : 0;
            }
            else if (j == 0)
            {
                dp[i][j & 1] = val[j];
            }
            else
            {
                dp[i][j & 1] = max(dp[i][(j + 1) & 1], dp[i - wt[j]][(j + 1) & 1] + val[j]);
            }
        }
    }
    return dp[W][(n - 1) & 1];
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}