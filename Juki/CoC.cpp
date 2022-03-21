

#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <string>

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

    string szs;
    int N, C, ak, bk; //N = Number of characters; C =Troops that die; ak = first interval; bK=  last interval;  [ak,bk]
    while (getline(cin, szs) && !szs.empty())
    {
        stringstream ss(szs);
        ss >> N >> C;

        vector<string> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        pair<int, int> interval(1e5 + 4, 0); //Cota superior 10e5
        for (int i = 0; i < C; i++)
        {
            cin >> ak >> bk;
            ak -= 1;
            bk -= 1;
            if (ak < interval.first)
            {
                interval.first = ak;
            }
            if (bk > interval.second)
            {
                interval.second = bk;
            }
            if (interval.first - 1 >= 0)
            {
                cout << arr[interval.first - 1] << "[" << interval.first << "] ";
            }
            else
                cout << "- ";
            if (interval.second + 1 < arr.size())
            {
                cout << arr[interval.second + 1] << "[" << interval.second + 2 << "] ";
            }
            else
                cout << "- ";
            cout << "\n";
            cin.ignore();
        }
    }
}