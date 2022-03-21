

#include <iostream>
#include <sstream>
#include <set>
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

    priority_queue<pair<int, string> > p;
    string name, line;
    int num;
    cin >> name >> num;
    pair<int, string> fP(num, name);

    p.push(fP);
    cin.ignore();
    while ((getline(cin, line)) && !line.empty())
    {
        stringstream ss(line);
        ss >> name;
        if (name == "V")
        {
            if (p.size() == 0)
            {
                cout << "\n";
                continue;
            }
            cout << p.top().second << endl;
            p.pop();
        }
        else
        {
            ss >> num;
            fP.first = num;
            fP.second = name;
            p.push(fP);
        }
    }
}