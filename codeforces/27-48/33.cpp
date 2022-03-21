

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
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
    int N;
    cin >> N;
    vector<pair<int, int> > coordinates(N, pair<int, int>());
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        coordinates[i].first = x;
        coordinates[i].second = y;
    }
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        pair<int, int> superCentral(coordinates[i].first, coordinates[i].second);
        bool upper = false, lower = false, left = false, right = false;
        for (int j = 0; j < N; j++)
        {
            int xP = coordinates[j].first, yP = coordinates[j].second, x = superCentral.first, y = superCentral.second;
            if (j == i)
                continue;
            else if (x == xP && y < yP)
                upper = true;
            else if (x == xP && y > yP)
                lower = true;
            else if (x < xP && y == yP)
                right = true;
            else if (x > xP && y == yP)
                left = true;
        }
        if (upper && lower && right && left)
            cont++;
    }
    cout << cont << "\n";
}