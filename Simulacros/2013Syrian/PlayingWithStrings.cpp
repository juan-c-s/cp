

#include <iostream>
#include <vector>
#include <string>
#include <map>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
#define INF 10000000

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
    cin >> N;
    string line;
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        map<char, int> f;
        for (int j = 0; j < line.size(); j++)
        {
            f[line[j]]++;
        }
        int impar = 0;
        string palindrome = "";
        char imparS = ' ';
        for (map<char, int>::iterator j = f.begin(); j != f.end() && impar < 2; j++)
        {
            if (j->second % 2 == 1)
            {
                impar++;
                imparS = j->first;
            }
        }
        if (impar >= 2)
            cout << "impossible\n";
        else
        {

            for (map<char, int>::iterator j = f.begin(); j != f.end(); j++)
            {
                for (int k = 0; k < j->second / 2; k++)
                {
                    palindrome.push_back(j->first);
                }
            } //PARTE DE ADELANTE
            if (imparS != ' ')
                palindrome.push_back(imparS);

            for (map<char, int>::reverse_iterator j = f.rbegin(); j != f.rend(); j++)
            {
                for (int k = 0; k < j->second / 2; k++)
                {
                    palindrome.push_back(j->first);
                }
            }
            cout << palindrome << "\n";
        }
    }
}
