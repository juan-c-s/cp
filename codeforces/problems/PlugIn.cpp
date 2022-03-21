

#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <string>
#include <deque>
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
    string text;
    getline(cin, text);
    deque<char> stack;

    for (int i = 0; i < text.size(); i++)
    {
        if (stack.size() != 0 && text[i] == stack.back())
        {
            stack.pop_back();
        }
        else
            stack.push_back(text[i]);
    }
    while (!stack.empty())
    {
        cout << stack.front();
        stack.pop_front();
    }
    cout << "\n";
}