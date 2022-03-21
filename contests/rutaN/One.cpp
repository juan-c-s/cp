#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){

        int a, b;

        cin >> a >> b;

        if ((a-b) >= 10){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }

    return 0;
}