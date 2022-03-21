

#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <unordered_map>

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
    int N, Q, x, y; //n = personas; Q = queries
    cin >> N >> Q;
    vector<pair<int, int> > rangos(N + 1, pair<int, int>(0, 0)); /// pair<LOL,DOTA>

    string szs;
    for (int i = 1; i <= N; i++)
    {
        cin >> szs;
        if (!szs.compare("DOTA"))
        {
            rangos[i].second = rangos[i - 1].second + 1;
            rangos[i].first = rangos[i - 1].first;
        }
        else
        {
            rangos[i].first = rangos[i - 1].first + 1;
            rangos[i].second = rangos[i - 1].second;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "( " << rangos[i].first << ", " << rangos[i].second << "), ";
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y;

        cout << x << ", " << y << "): " << rangos[y].first - rangos[x - 1].first << ">" << rangos[y].second - rangos[x - 1].second << "\n";
        if (rangos[y].first - rangos[x - 1].first > rangos[y].second - rangos[x - 1].second)
        {
            cout << "LOL\n";
        }
        else if (rangos[y].first - rangos[x - 1].first < rangos[y].second - rangos[x - 1].second)
        {
            cout << "DOTA\n";
        }
        else
            cout << "AFK\n";
    }
}