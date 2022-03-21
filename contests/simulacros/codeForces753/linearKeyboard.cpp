

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>

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
        string alphabet;
        unordered_map<char, int> pos;
        cin >> alphabet;
        for (int i = 0; i < 26; i++)
        {
            pos[alphabet[i]] = i;
        }
        string word;
        cin >> word;
        char prev = word[0];
        int cont = 0;
        for (int i = 1; i < word.size(); i++)
        {
            cont += abs((pos[word[i - 1]] + 1) - (pos[word[i]] + 1));
        }
        cout << cont << "\n";
    }
}