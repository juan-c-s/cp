

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
    string time1, time2, hour1, min1, hour2, min2;
    getline(cin, time1);
    getline(cin, time2);
    hour1.push_back(time1[0]);
    hour1.push_back(time1[1]);
    min1.push_back(time1[3]);
    min1.push_back(time1[4]);
    hour2.push_back(time2[0]);
    hour2.push_back(time2[1]);
    min2.push_back(time2[3]);
    min2.push_back(time2[4]);

    int h1, h2, m1, m2, resultantH, resultantM;
    double residuo;
    h1 = convert(hour1);
    h2 = convert(hour2);
    m1 = convert(min1);
    m2 = convert(min2);
    residuo = ((int)(((h1 + h2) / 2.0) * 100)) % 100;
    resultantH = (h1 + h2) / 2;

    resultantM = ((m1 + m2) / 2) + ((int)((residuo / 100.0) * 60.0));
    if (resultantM > 59)
    {
        resultantH++;
        resultantM -= 60;
    }
    cout << convert(resultantH) << ":" << convert(resultantM) << endl;
}