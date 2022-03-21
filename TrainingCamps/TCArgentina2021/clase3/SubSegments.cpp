

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <typeinfo>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    multiset<int> frequency; //This is to avoid repeated numbers
    set<int> segment;        // This is to have the numbers ordered; this can help by accessing the last element

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < k; i++)
    {
        if (frequency.count(arr[i]) == 0)
        {
            segment.insert(arr[i]);
        }
        else
            segment.erase(arr[i]);

        frequency.insert(arr[i]);
    }
    if (segment.size() == 0)
        cout << "Nothing\n";
    else
        cout << *segment.rbegin() << endl;

    for (int i = k; i < n; i++)
    {
        set<int>::iterator s = frequency.find(arr[i - k]);
        //Al tener el iterador, se le puede restar la frecuencia al multiset
        frequency.erase(s);

        if (frequency.count(arr[i - k]) == 0 && segment.count(arr[i - k]) > 0)
        { //Checkiando si el arr[i-k] era el numero que estaba en la pasada
            segment.erase(arr[i - k]);
        }
        else if (frequency.count(arr[i - k]) == 1 && segment.count(arr[i - k]) == 0)
        {
            //En este caso, el programa está checkiando que se agregue al set el numero que era repetido con el anterior
            //Osea [4,4,3,2,1] k = 3; entonces en la primera corrida devuelve 3 porque 4 está repetido. Pero despues la ventana
            //"k" se mueve y no incluye el primer 4 entonces ya no estaría repetido y podría ser el mayor del segmento
            segment.insert(arr[i - k]);
        }

        if (frequency.count(arr[i]) == 0)
        {
            segment.insert(arr[i]);
        }
        else
            segment.erase(arr[i]);

        frequency.insert(arr[i]);

        if (segment.size() == 0)
            cout << "Nothing\n";
        else
            cout << *segment.rbegin() << endl;
    }
}