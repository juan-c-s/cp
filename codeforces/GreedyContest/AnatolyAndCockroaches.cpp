

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

    int N;
    string line;
    cin >> N >> line;

    char currLet = line[0];

    int counter = 1, moves = 0;

    for (int i = 1; i < N; i++)
    {

        while (currLet == line[i] && i < N)
        {
            i++;
            counter++;
        }
        if (counter > 2)
        {

            moves += (counter % 2 == 0) ? (counter / 2) : ((counter - 1) / 2);

            if (i < N)
                currLet = line[i];

        } //SI HAY MAS DE 2, ENTONCES DIVIDA ESO POR 2 Y LE DA LOS MOVIMIENTOS. ASIGNAR LA LETRA ACTUAL QUE SERÍA DIFERENTE A LA PRIMERA
        else if (counter == 2)
        {
            if (i < N)
            {
                char temp = line[i - 1];
                line[i - 1] = line[i]; //LA ANTERIOR SERÍA LA QUE ALCANZÓ A PASAR EL WHILE
                                       // Y LA ACTUAL SERÍA LA QUE TUMBÓ EL WHILE
                line[i] = temp;
                moves++;
                currLet = line[i];
                // DBG(line[i - 1]);
                // RAYA;
                // DBG(line[i]);
                // RAYA;
                // DBG(i);
                // RAYA;
            }
            else
                moves++;
        }
        else
        {
            currLet = line[i];
        }
        counter = 1;
    }
    cout << moves << "\n";
}