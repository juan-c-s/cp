

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

    vi sieve(MAX, 0); //Los primos son los numeros que tienen 0

    for (int i = 2; i < MAX; i++)
    {
        if (!sieve[i])
            for (int j = 2 * i; j < MAX; j += i)
            {
                sieve[j] = 1; //1 = no primo,
            }
    }
    vi um;
    for (int i = 2; i < MAX; i++)
    {
        if (!sieve[i])
        { //si es primo
            if ((i - 2 >= 0 && !sieve[i - 2]) || i + 2 < MAX && !sieve[i + 2])
            {
                // 2 numeros antes tambien es primo
                um[i] = 1;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
    }

    while (N--)
    {
        int num;
        cin >> num;
    }
}