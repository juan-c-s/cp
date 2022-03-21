

#include <iostream>
#include <vector>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, value, taxis = 0;
    cin >> N;
    vector<int> available(5, 0);
    for (int i = 0; i < N; i++)
    {
        bool szs = false;
        cin >> value;
        for (int j = value; j < 5; j++)
        {
            if (available[j] > 0)
            {
                szs = true;
                available[j - value]++; //le agrega uno al contenedor que sea lo que quedó del contenedor anterior al restarle el valor
                available[j]--;         //ya el contenedor no será disponible por el mismo valor
                break;
            }
        }
        if (!szs)
        {
            available[4 - value]++;
            taxis++;
        }
    }

    cout << taxis << endl;
}