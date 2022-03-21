

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <bitset>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() > v2.size())
        return findMedianSortedArrays(v2, v1);
    int x = v1.size();
    int y = v2.size();

    int start = 0, end = x;
    while (start <= end)
    {
        int separateInX = (end + start) / 2;
    }
}

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    double ans = findMedianSortedArrays(v, a);
    DBG(ans);
}
