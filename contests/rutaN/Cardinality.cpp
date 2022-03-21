#include <bits/stdc++.h>
using namespace std;

int main(){
    

    while(true){
        int A,B;
        cin>>A>>B;  

        if(A == 0 && B == 0){
            break;
        }
        map<int, int> a;
        map<int, int> b;
        map<int, int> uni;
        for (int i = 0; i < A; i++)
        {
            int num;
            cin>>num;
            a[num] = 1;
            uni[num] = 1;
        }
        for (int i = 0; i < B; i++){
            int num;
            cin>>num;
            b[num] = 1;
            uni[num] = 1;
        }

        int temp = max(A, B);

        int j = 0,unio = 0,inter = 0,difA = 0,difB = 0;

        map<int,int>::iterator ai = a.begin();
        map<int,int>::iterator bi = b.begin();

        for(int i = 0; i<= temp; i++){
            
            if(i < A){
                if(b[ai->first] != 1){
                    difA++;
                }else{
                    cout << " " <<ai->first<< endl;
                    inter++;
                }
            }if(i < B){
                // cout <<  << endl;
                if(a[bi->first] !=1){
                    difB++;
                }
            }

            ai++;
            bi++;
        }
        unio = uni.size();
        cout<< difA << " " <<inter << " " << difB << " " << unio << endl;

        
        
    }
    return 0;
}