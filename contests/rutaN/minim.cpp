#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double cont =0;
    for (int i = 0; i < n; i++)
    {
        double num ;
        cin>>num;
        if(num==0){
            cont+=2;
        }else cont+=(1/num);
    }
    cout<<cont<<"\n";
    
    return 0;
}