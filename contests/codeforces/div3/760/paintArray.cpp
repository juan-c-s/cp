

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    // la idea es conseguir factores comunes de numeros separados de a 2 if(i%2==0)
    //despues iterar por la lista y encontrar un factor que no sea divisible por los (i%2==1)
    //gcd(a,b,c) = gcd(a,gcd(a,b))
    //gcd(n) = gcd(n1,gcd(n2,gcd(n3,...n)));
    //aqui encuentro el factor común más grande

    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> list(N);
        for (int i = 0; i < N; i++)
        {
            cin >> list[i];
        }

        ll factorComunMasGrande = list[0];
        for (int i = 2; i < N; i += 2)
        {
            factorComunMasGrande = gcd(list[i], factorComunMasGrande);
        }
        ll factorComunMasGrandeImpares = list[1];
        for (int i = 3; i < N; i += 2)
        {
            factorComunMasGrandeImpares = gcd(list[i], factorComunMasGrandeImpares);
        }

        // for (int i = 0; i < factors.size(); i++)
        // {
        //     cout << factors[i] << " ";
        // }
        // cout << endl;

        bool gcdPar = true;
        int respuesta;

        bool gcdImpar = true;
        for (int j = 0; j < N; j++)
        {
            if (j & 1) //si es impar
            {
                if (list[j] % factorComunMasGrande == 0)
                {
                    gcdPar = false;
                }
            }
            else
            {
                if (list[j] % factorComunMasGrandeImpares == 0)
                {
                    gcdImpar = false;
                }
            }
        }

        if (gcdPar)
        {
            cout << factorComunMasGrande << "\n";
        }
        else if (gcdImpar)
        {
            cout << factorComunMasGrandeImpares << "\n";
        }
        else
            cout << "0\n";
    }
}