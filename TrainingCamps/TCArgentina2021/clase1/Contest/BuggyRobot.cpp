#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

#include <iostream>
#include <string>

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int commands;
    cin >> commands;

    string instructions;

    cin >> instructions;
    int movements = 0; //movements to return to the original spot
    pair<int, int> robot(0, 0);
    char currIns;
    for (int i = 0; i < instructions.length(); i++)
    {
        currIns = instructions.at(i);
        if (currIns == 'U')
        {
            robot.second++;
        }
        else if (currIns == 'D')
        {
            robot.second--;
        }
        else if (currIns == 'L')
        {
            robot.first--;
        }
        else if (currIns == 'R')
        {
            robot.first++;
        }

        if (robot.first == 0 && robot.second == 0)
        {
            movements = i + 1;
        }
    }
    cout << movements << endl;
}