#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;
    set<int>s;
    for (int i = 0; i < T; i++)
    {
        int num;
        cin>>num;
        s.insert(num);
    }
    set<int>::iterator min = s.begin();
    set<int>::iterator max = s.end();
    max--;
    cout<<*min<<endl;
cout<<*max<<endl;

    
    return 0;
}