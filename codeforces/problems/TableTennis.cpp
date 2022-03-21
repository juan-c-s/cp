

#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl
#define ll long long

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll P, W; //P = personas; W = wins o partidos de tenis
    cin >> P >> W;
    vector<int> personas(P);
    for (int i = 0; i < P; i++)
    {
        cin >> personas[i];
    }
    int winner = personas[0];
    int index = 1;
    int contador = 0;

    while (contador < W)
    {

        if (index == P)
        {

            break;
        }
        if (personas[index] > winner)
        {
            winner = personas[index++];
            contador = 1;
        }
        else if (personas[index] < winner)
        {
            index++;
            contador++;
        }
    }
    cout << winner << endl;
}