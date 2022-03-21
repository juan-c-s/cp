

#include <iostream>
#include <set>
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
    int T, N, num;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<int> repeated; //repeated elements
        set<int> s;
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (s.size() > 0 && s.find(num) != s.end())
            {
                repeated.push_back(num);
            }
            else
                s.insert(num);
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        for (int j = 0; j < repeated.size(); j++)
        {
            cout << repeated[j] << " ";
        }
        cout << endl;
    }
}