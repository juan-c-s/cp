#include <numeric>
#include <algorithm>

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
int convert(string s)
{
    string sizas = "";
    if (s[0] == '0')
    {
        sizas.push_back(s[1]);
        return stoi(sizas);
    }
    sizas.push_back(s[0]);
    sizas.push_back(s[1]);
    return stoi(sizas);
}
string convert(int i)
{
    string szs = "";
    if (i / 10 == 0)
    {
        szs = "0";
    }

    return szs + to_string(i);
}
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++)
    // {

    // }
    cout << __lcm(10, 34) << endl;
}