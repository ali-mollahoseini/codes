#include <bits/stdc++.h>

#define ll long long

const int inf=0x7FFFFFFF;
const int MX1=5*1000+1000;
ll dp[MX1][MX1];
int fr[MX1],ls[MX1],a[MX1];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(fr[a[i]]==0){
            fr[a[i]]=i+1;
        }
        ls[a[i]]=i+1;
    }
    //if(ls[a[0]]==0){
    //    dp[0]=a[0];
    //}
    for(int i=0;i<n;i++){
        if(ls[a[i]]==i+1){
            int anstmp=0;
            for(int j=fr[a[i]]-1;j<i+1;i++){
                if()
            }
        }else{
            dp[i]=dp[i-1];
        }
    }
}

