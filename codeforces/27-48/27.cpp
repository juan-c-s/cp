

#include <iostream>
#include <string>
#include <ctype.h>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int chartoInt(char c)
{
    if (isupper(c))
        return c - 'A';
    else
        return c - 'a';
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string w1, w2;
    getline(cin, w1);
    getline(cin, w2);
    int n = min(w1.size(), w2.size());
    short answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (chartoInt(w1[i]) > chartoInt(w2[i]))
        {
            answer = 1;
            break;
        }
        else if (chartoInt(w1[i]) < chartoInt(w2[i]))
        {
            answer = -1;
            break;
        }
    }
    if (answer == 0)
    {
        if (w1.size() > w2.size())
        {
            answer = 1;
        }
        else if (w1.size() < w2.size())
        {
            answer = -1;
        }
    }

    cout << answer << "\n";
}