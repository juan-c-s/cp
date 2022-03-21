#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> lista(n);
    cin.ignore();
    
    for (int i = 0; i < n; i++)
    {
        getline(cin,lista[i]);

    }
    sort(lista.begin(),lista.end());

    for(int i = 0; i < n; i++){
        cout << lista[i] << endl;
    }
    return 0;
}