#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=5*1000*1000+100;
ll t,r,l;
ll dp[MX1];
ll num[MX1];

void seive(int last){
    for(int i=2;i*i<=last;i++){
        if(num[i]==0){
            for(int j=i*2;j<=last;j+=i){
                //cout<<i;
                if(num[j]==0){
                    num[j]=i;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t>>l>>r;
    seive(r);
    ll total=0;
    //cerr<<lna<<endl;
    dp[1]=0;
    for(ll i =2;i<=r;i++){
        if (num[i]==0){
            dp[i]=i*(i-1)/2;
        }else{
            dp[i]=dp[i/num[i]]+i/num[i]*(num[i]*(num[i]-1)/2);
        }
    }
    ll zarib=1;
    for(ll i =l;i<=r;i++){
        total=(total+((dp[i]%mod)*zarib)%mod)%mod;
        zarib=(zarib*t)%mod;
    }
    cout<<total;
}

