#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#include <string>
#include <iostream>
#include <vector>
#include <limits>

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cont = 0, tempNum;
    cin >> n;

    vector<int> nums;
    nums.reserve(n);
    vector<int> aux;
    while (nums.size() > 0)
    {
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tempNum;
        nums.push_back(tempNum);
    }

    int j = 0;
    int prevNum = 0;
    while (j < nums.size())
    {

        cont += prevNum;
        int smallest = numeric_limits<int>::max();
        int smallestIndex = 0;
        //<------ ADDING NUMBERS IN LIST AND FINDING THE SMALLEST ELEMENT ------>
        for (int i = 0; i < n - j; i++)
        {
            if (nums[i] < smallest)
            {
                smallest = nums[i];
                smallestIndex = i;
            }
            cont += nums[i];
        }
        j++;

        //<------ SEPARATING THE LIST FROM THE SMALLEST ELEMENT ------>
        prevNum = nums[smallestIndex];
        nums[smallestIndex] = 0;
        swap(nums[smallestIndex], nums[n - j]);
    }
    cout << cont << endl;

    return 1;
}