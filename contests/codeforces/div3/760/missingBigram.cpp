

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

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
    int T;
    cin >> T;
    while (T--)
    {
        int N; //how big the word is
        cin >> N;
        vector<string> list(N - 2);
        for (int i = 0; i < N - 2; i++)
        {
            cin >> list[i];
        }

        string answer = list[0];
        for (int i = 1; i < N - 2; i++)
        {
            if (list[i - 1][1] != list[i][0])
            {
                answer.push_back(list[i][0]);
            }
            answer.push_back(list[i][1]);
        }

        if (answer.size() != N)
            answer.push_back('a');
        cout << answer << "\n";
    }
}