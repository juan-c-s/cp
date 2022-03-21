

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
    int N;
    char par;
    cin >> N;
    deque<char> p;

    for (int i = 0; i < N; i++)
    {
        cin >> par;
        if (par == ')' && p.size() > 0 && p.back() == '(')
        {
            p.pop_back();
        }
        else
            p.push_back(par);
    }

    if (p.size() == 0)
        cout << "Yes\n";
    else if (p.size() == 2)
    {
        char first = p.back();
        p.pop_back();
        if (first == '(' && p.back() == ')')
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    else
        cout << "No\n";

    // for (deque<char>::iterator it = p.begin(); it != p.end(); it++)
    // {
    //     cout << *it;
    // }
    // cout
    //     << endl;
}