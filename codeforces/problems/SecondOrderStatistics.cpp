

#include <iostream>
#include <set>
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
    int N, num;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        s.insert(num);
    }
    set<int>::iterator it = s.begin();
    it++;
    if (it != s.end())
        cout << *it << endl;
    else
        cout << "NO\n";
}