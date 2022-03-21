

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>

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
        int n, k;
        cin >> n >> k;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int smallestElements = n - (2 * k);
        int sum = 0;
        for (int i = 0; i < smallestElements; i++)
        {
            sum += v[i];
        }

        for (int i = smallestElements; i + k < n; i++)
        {
            sum += v[i] / v[i + k];
            //si hay mas de k números consecutivos, habrán parejas si o si de tal forma (x,x)
            //Además que en el subArreglo a emparejar hay 2*k elementos entonces solamente se recorre n-k posiciones ya que sería la mitad
            //del segundo subArreglo que garantiza que ya las parejas estarán seleccionadas
        }
        cout << sum << "\n";
    }
}