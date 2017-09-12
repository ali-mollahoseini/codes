#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000*100;

const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10069;
const int mod=1000*1000*1000+7;

ll ar[MX1],ar1[MX1];

ll poww(ll a,ll b){
    ll ans=1;
    while(b){
        ans*=a;
        b--;
    }
    //cout<<1;
    return ans;
}
ll tarkib(ll r,ll n){
    cerr<<n-r<<" "<<endl;
    for(int i=0;i<n-r;i++){
        ar[i]=i+r+1;
        ar1[i]=i+1;
    }
    for(int i=0;i<n-r;i++){
        for(int j=0;j<n-r;j++){
            ll x=__gcd(ar[i],ar1[j]);
            ar[i]/=x;
            ar1[j]/=x;
        }
    }
    ll ans=1;
    for(int i=0;i<n-r;i++){
        ans*=ar[i];
        ans%=mod;
    }
    return ans;
}
int main(){
    ll t,k,n;
    cin>>n>>t>>k;
    int ans=tarkib(k-t+1,poww(2,n)-t)*tarkib(t,poww(2,n))%mod;
    while(ans<0){
        ans+=delta;
    }
    //cout<<1;
    cout<<ans%delta;
}
