#include <bits/stdc++.h>

#define ll long long

const int inf=0x7FFFFFFF;
const int MX1=5*1000+1000;
using namespace std;
int main(){
    int a,b ;
    cin>>a>>b;
    int cntr=0;
    int mont=1;
    bool tf=1;
    while(tf){
        if(cntr%2==0){
            if(a<mont){
                tf=0;
                break;
            }else{
                a-=mont;
            }
        }else{
            if(b<mont){
                tf=0;
                break;
            }else{
                b-=mont;
            }
        }
        cntr++;
        mont++;
    }
    if(cntr%2==0){
        cout<<"Vladik"<<endl;
    }else {
        cout<<"Valera"<<endl;
    }
}

