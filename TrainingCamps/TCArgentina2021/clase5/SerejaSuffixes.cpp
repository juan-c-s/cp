

#include <iostream>
#include <map>
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

    int n, m, num;
    cin >> n >> m;

    map<int, int> frequency;
    vector<int> b(n); //Storing the elements that will

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        frequency[b[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> num;

        int distinctIntegers = frequency.size();

        cout << distinctIntegers << endl;

        if (frequency[b[i]] - 1 <= 0)
        {
            frequency.erase(b[i]);
        }
        else
            frequency[b[i]]--;
    }
}