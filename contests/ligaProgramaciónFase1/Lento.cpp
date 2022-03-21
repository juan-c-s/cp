

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e7 + 1 //MAX number is 1e6
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
    int n;
    ll sumaImpares = 0, contPares = 0, imparMenor = MAX;
    cin >> n;
    vector<ll> impares;

    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        if (num <= 0)
            continue;
        if (num & 1)
        {
            impares.push_back(num);
            sumaImpares += num;
            imparMenor = min(num, imparMenor);
        }
        else
            contPares += num;
    }
    if (impares.size() == 0 || !n)
    {
        cout << "0\n";
    }
    else if (impares.size() & 1)
    {
        cout << contPares + sumaImpares << "\n";
    }

    else
        cout << contPares + sumaImpares - imparMenor << "\n";
}