
#include <iostream>
#include <string>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
    }
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<char> > matrix(N, (vector<char>(M)));
    vector<vector<pair<int, int> > > dp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<pair<int, int> > > dp(matrix.size(), vector<pair<int, int> >(matrix[0].size(), pair<int, int>()));
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == '0')
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
            else
            {
                if (j > 0)
                    dp[i][j].first = dp[i][j - 1].first + 1;
                else
                    dp[i][j].first = 0;
                if (i > 0)
                    dp[i][j].second = dp[i - 1][j].second + 1;
                else
                    dp[i][j].second = 0;
            }
        }
    }
    int maxRect = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (dp[i][j].first != -1 && (dp[i][j].first == 0 || dp[i][j].second == 0))
            {
                int rI = i + 1, mini = dp[i][j].first + 1, c = 1;
                while (i + 1 < N && dp[rI][j].first != -1)
                {
                    mini = min(mini, dp[rI][j].first + 1);
                }
                maxRect = max(mini * c, maxRect);
            }
            else
            {
                maxRect = max(maxRect, dp[i][j].first != -1 ? dp[i][j].first : dp[i][j].second);
            }
        }
    }
}