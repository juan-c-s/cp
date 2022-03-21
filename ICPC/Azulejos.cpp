

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#define DBG(x) cerr < < #x < < " = " << (x) < < endl;
#define RAYA cerr << "=============================" << endl;
#define ll long long

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
struct tile
{
    int height;
    int price;
    int index;

    tile(int h, int p, int i)
    {
        height = h;
        price = p;
        index = i;
    }
    tile() {}

    bool operator<(tile const &other) const
    {
        if (other.price > price)
            return true;
        else if (other.price == price)
        {
            if (other.height < height)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<tile> > tiles(2, vector<tile>(N)); //0 is front row, 1 is back row // first es el precio, second, altura
    for (int i = 0; i < N; i++)
    {

        cin >> tiles[1][i].price;
        tiles[1][i].index = i;
    }
    for (int i = 0; i < N; i++)
    {

        cin >> tiles[1][i].height;
        tiles[1][i].index = i;
    }
    for (int i = 0; i < N; i++)
    {

        cin >> tiles[0][i].price; //price of front row
        tiles[0][i].index = i;
    }
    for (int i = 0; i < N; i++)
    {

        cin >> tiles[0][i].height;
        tiles[0][i].index = i;
    }
    sort(tiles[0].begin(), tiles[0].end());
    sort(tiles[1].begin(), tiles[1].end());
    bool works = true;
    string answer = "";
    for (int i = 0; i < N && works; i++)
    {
        if (tiles[0][i].height >= tiles[1][i].height)
        {
            works = false;
        }
    }
    if (!works)
        answer = "impossible\n";
    else
        for (int j = 1; j >= 0; j--)
        {

            for (int i = 0; i < N; i++)
            {
                answer += to_string(tiles[j][i].index + 1) + " ";
            }
            answer += "\n";
        }
    cout << answer;
}
