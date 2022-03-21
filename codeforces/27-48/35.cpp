

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
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
    int x, y, z;
    cin >> x >> y >> z;

    int a = sqrt((x * y) / z);
    int b = sqrt((y * z) / x);
    int c = sqrt((x * z) / y);

    cout << (a + b + c) * 4 << endl;
}