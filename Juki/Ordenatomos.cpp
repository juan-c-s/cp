

#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
int N = 100000;
vector<int> criba;

struct INT
{

    int numero;
    INT() {}
    INT(int num)
    {
        numero = num;
    }
    bool operator<(INT const &other) const
    {
        if (criba[numero] == criba[other.numero])
        {
            return numero < other.numero;
        }
        else if (criba[numero] == 0 && criba[other.numero]) //numero actual es primo y el otro no(true significa que si es menor)
            return true;
        else
            return false; //el numero actual no es primo y el otro si
    }
};
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;

    cin >> m;

    vector<INT> lista(m);
    int szs, maxi = 0;
    for (int i = 0; i < m; i++)
    {

        cin >> szs;
        lista[i] = INT(szs);
        cout << lista[i].numero << " ";
        maxi = max(maxi, szs);
    }
    criba.reserve(maxi);

    cout << "empezo" << maxi << "e\n";

    sort(lista.begin(), lista.end());
    int cont = 0;
    map<int, vector<int> > primos;
    for (int i = 0; i < m; i++)
    {
        if (criba[lista[i].numero] == 1) //NO ES PRIMO
        {
            continue;
        }
        else
        {
            vector<int> list;
            primos[lista[i].numero] = list;
            //CUANDO ES PRIMO, IGUALAR A 1 TODOS SUS FACTORES
            for (int j = 2 * lista[i].numero; j <= maxi; j += lista[i].numero)
            {
                criba[j] = 1;
            }
        }
    }
    cout << "s\n";

    sort(lista.begin(), lista.end());
    // cout << "[";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << lista[i].numero << ", ";
    // }
    // cout << "]\n";

    for (int i = m - 1; i >= 0; i--)
    {
        if (criba[lista[i].numero] == 1)
            continue;
        else
        {
            //si es primo, iterar en la lista encontrando sus factores y añadiendolo a la lista
            for (int j = m - 1; j >= 0; j--)
            {
                if (criba[lista[j].numero] == 0)
                    continue;
                else
                {
                    if (lista[j].numero % lista[i].numero == 0)
                    {
                        criba[lista[j].numero] = 0;
                        primos[lista[i].numero].push_back(lista[j].numero);
                    }
                }
            }
        }
    }

    for (map<int, vector<int> >::iterator it = primos.begin(); it != primos.end(); it++)
    {
        cout << it->first << " ";
        sort(it->second.begin(), it->second.end());
        for (int i = 0; i < it->second.size(); i++)
        {

            cout << it->second[i] << " ";
        }
    }
}