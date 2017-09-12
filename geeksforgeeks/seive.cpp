//in the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=10000+100;

int n[MX1],t;
int num[MX1];
void seive(int ar[],int mx){
    for(int i=2;i*i<=mx;i++){
        if(ar[i]==0){
            for(int j=2*i;j<=mx;j+=i){
                if(ar[j]==0){
                    ar[j]=i;
                }
            }
        }
    }
}
int main(){
    cin>>t;
    int mx=0;
    for(int i =0;i<t;i++){
        cin>>n[i];
        mx= max(mx,n[i]);
    }
    seive(num,mx);
    for(int i=0;i<t;i++){
        for(int j=2;j<=n[i];j++){
            if(num[j]==0){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;

}
