
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define LL long long

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        LL h;
        cin >> n >> h;

        vector<LL> v(n - 1);
        LL before;
        cin >> before;
        for (int i = 0; i < n - 1; i++)
        {
            LL now;
            cin >> now;
            v[i] = now - before;
            before = now;
        }

        LL left = 0;
        LL right = 10e18;
        while (left + 1 < right)
        {
            LL mid = left + (right - left) / 2;
            LL sum = mid;
            for (auto x : v)
            {
                sum += min(x, mid);
            }
            if (sum >= h)
                right = mid;
            else
                left = mid;
        }

        cout << right << endl;
    }

    return 0;
}