#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;
    while(T--){
        int Q,min=10e5,max=0;
        cin>>Q;
        set<int> szs;
        for (int i = 0; i < Q; i++)
        {
            int query;
            cin>>query;
            set<int>::iterator min;
            set<int>::iterator max;
            if(query == 1){
                int num;
                cin>>num;
                szs.insert(num);
            }else if(query == 2){
                if(szs.size() >0){
                    max = szs.end();
                    max--;
                    cout<<*max<<"\n";
                    szs.erase(max);
                }
            }else if(query == 3){
                if(szs.size() >0){
                    max = szs.end();
                    min = szs.begin();
                    max--;
                    cout<<*max-*min <<"\n";
                  
                }
                else
                    cout<<"Empty!\n";
            }
        }
        
    }
    return 0;
}