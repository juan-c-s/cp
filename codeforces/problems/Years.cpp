

#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl
#define INF 10e6 //cota superior es 30

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, born, died; //V = Vertices, E = vias tren(edges), Q = queries, T = tiempo
    cin >> N;
    vector<pair<int, int> > arr(N);
    map<int, int> year;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        for (int j = arr[i].first; j < arr[i].second; j++)
        {
            year[j]++;
        }
    }
    int peoplelived = 0;
    for (map<int, int>::iterator it = year.begin(); it != year.end(); it++)
    {
        if (it->second > year[peoplelived])
        {
            peoplelived = it->first;
        }
        else if (year[peoplelived] == it->second && it->first < year[peoplelived])
        {
            peoplelived = it->first;
        }
    }
    cout << peoplelived << " " << year[peoplelived] << "\n";
}