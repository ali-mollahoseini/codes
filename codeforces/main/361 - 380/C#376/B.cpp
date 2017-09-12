#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
int a[MX2],n,m;
int sum;
int main(){
    cin>>n;
    bool tf=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        if(a[i]%2==1){
            if(i==n-1||a[i+1]==0){
                tf=0;
                break;
            }else if(i!=n-1){
                a[i+1]--;
            }
        }
    }
    if(tf){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
