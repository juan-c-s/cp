

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

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
    int N, snow, melts, stayed = 0;
    cin >> N;
    vector<pair<int, int> > days(N); //list of days; first = snow and second = melts
    for (int i = 0; i < N; i++)
    {
        cin >> snow;
        days[i]
            .first = snow;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> melts;
        days[i].second = melts;
    }

    for (int i = 0; i < N; i++)
    {
        snow = days[i].first;
        melts = days[i].second;
        if (melts >= stayed)
        {
            cout << melts + stayed << " ";
            stayed = snow - melts;
        }
        else
        {
            cout << melts + melts << " ";
            stayed = (snow - melts) + (stayed - melts);
        }
    }
}