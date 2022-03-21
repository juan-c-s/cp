

#include <iostream>
#include <vector>

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
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        cin >> m;
        vector<int> l(m);
        int index = 0, firstNum, rep, sec;
        cin >> firstNum;
        rep = firstNum;
        l[0] = firstNum;
        for (int j = 1; j < m; j++)
        {
            cin >> l[j];
            if (found)
                continue;
            if (l[j] != rep)
            {
                found = true;
                if (j == 1)
                {
                    cin >> l[j + 1];
                    if (l[j + 1] == l[j])
                    {
                        rep = l[j++];
                        continue;
                    }
                    else
                    {
                        index = 1;
                        j++;
                        continue;
                    }
                }
                else
                    index = j;
            }
        }
        cout << index + 1 << endl;
    }
}