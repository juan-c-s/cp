

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

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
        int R, C;
        cin >> R >> C;
        vector<vector<char> > m(R, vector<char>(C));
        pair<int, int> start, end;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == 'S')
                {
                    start.first = i;
                    start.second = j;
                }
                else if (m[i][j] == 'X')
                {
                    end.first = i;
                    end.second = j;
                }
            }
        }

        //hacer bfs
        vector<string> routes;
        vector<vector<int> > costo(R, vector<int>(C));
        queue<pair<pair<pair<int, int>, string>, vector<string> > > q;
        q.push(start);
        while (!q.empty())
        {
            int x = q.front().first.first.first;
            int y = q.front().first.first.second;
            string actualPath = q.front().first.second; //ruta actual desde el comienzo
            vector<string> paths = q.front().second;
            q.pop();

            if (x + 1 < R && (m[x][y] == '.' || m[x][y] == 'X'))
            {
                //U
                paths.push_back(actualPath + 'U');
                if (m[x][y] == 'X')
                    routes.push_back(paths[paths.size() - 1]);
            }
        }
    }
}