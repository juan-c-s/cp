
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <string.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define MAX 2e6

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
typedef long long ll;
map<string, int> ss;
void recursion(string s)
{
    if (s.size() == 3)
        ss[s] = 1;
    else if (s.size() == 2)
    {
        ss[s] = 1;
        recursion(s + "4");
        recursion(s + "7");
    }
    else
    {
        ss[s] = 1;
        recursion(s + "4");
        recursion(s + "7");
    }
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num;
    cin >> num;
    recursion("");
    bool szs = false;
    for (map<string, int>::iterator itt = ss.begin(); itt != ss.end(); itt++)
    {
        if (itt->first != "")
        {
            if (num % stoi(itt->first) == 0)
            {
                szs = true;
                break;
            }
        }
    }
    cout << (szs ? "YES\n" : "NO\n");
}
