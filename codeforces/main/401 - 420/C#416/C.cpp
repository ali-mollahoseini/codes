#include <bits/stdc++.h>

#define ll long long

const int inf=0x7FFFFFFF;
const int MX1=5*1000+1000;
using namespace std;
ll dp[MX1];
ll fr[MX1],ls[MX1],a[MX1];
ll n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(fr[a[i]]==0){
            fr[a[i]]=i+1;
        }
        ls[a[i]]=i+1;
    }
    if(ls[a[0]]==1){
        dp[0]=a[0];
    }
    for(int i=1;i<n;i++){
        if(ls[a[i]]==i+1){
            ll l=fr[a[i]];
            ll anstmp=0;
            bool tf=1;
            //cout<<"L:"<<ls[a[i]]-1<< " "<<l-2<<endl;;
            for(int j=ls[a[i]]-1;j>l-2;j--){
                if(ls[a[j]]==j+1){
                    l=min(l,fr[a[j]]);
                    anstmp^=a[j];
                }else if(ls[a[j]]>ls[a[i]]){
                    dp[i]=dp[i-1];
                    tf=0;
                    break;
                }
                    //cout<<1<< " ";
            }
            if(tf){
                if(l<2){
                    dp[i]=max(dp[i-1],anstmp);
                    continue;
                }
                dp[i]=max(dp[i-1],dp[l-2]+anstmp);
                //cout<<anstmp<< " "<<dp[i] <<endl;
            }
        }else{
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[n-1]<<endl;
}
