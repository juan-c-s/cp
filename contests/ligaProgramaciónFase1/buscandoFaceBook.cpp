

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1
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
    int T;
    cin >> T;
    char fb[] = {'f', 'a', 'c', 'e', 'b', 'o', 'o', 'k'};
    for (int i = 0; i < T; i++)
    {
        string word;
        cin >> word;
        unordered_map<char, int> um;
        int fbIndex = 0;
        bool nosepuede = false;
        if (word.size() < (sizeof(fb) / sizeof(fb[0])))
            nosepuede = true;
        else
            for (int j = 0; j < word.size(); j++)
            {
                if (fbIndex < (sizeof(fb) / sizeof(fb[0])) && word[j] == fb[fbIndex])
                {
                    if (fbIndex != 0 && um[fb[fbIndex - 1]] < 1)
                    {
                        nosepuede = true;
                        // DBG(nosepuede);
                        // DBG(word[fbIndex - 1]);
                    }
                    // DBG(um[word[j - 1]]);
                    um[word[j]]++;
                    // DBG(word[j]);
                    // DBG(um[word[j]]);
                    fbIndex++;
                }
                else if (fbIndex == (sizeof(fb) / sizeof(fb[0])))
                    break;
            }
        if (fbIndex != (sizeof(fb) / sizeof(fb[0])))
            nosepuede = true;
        cout << "Case #" << i + 1
             << ": " << (nosepuede ? "NO" : "YES") << "\n";
    }
}