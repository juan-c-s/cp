#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    if (num - 1 % num == 0)
    {
        cout << num << endl;
    }
    else
        cout << "1\n";
}