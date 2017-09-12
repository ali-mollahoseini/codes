//in the name of Allah
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
const ll MX1=2*1000*1000+1000;
const ll inf= 0x7FFFFFFF;
#define ll long long

using namespace std;
pair<ll,ll> anss[MX1];
ll n,k;
int main(){
    cin>>n>>k;
    ll cnt=0;
    ll mod=1;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            anss[cnt]={i,n/i};
            cnt++;
            if(n/i==i){
                mod=2;
            }
        }
    }
    //cout<<cnt;
    if(k<=cnt){
        cout<<anss[k-1].first;
    }else{
        k-=cnt;
        if(mod==1){
            if(k>cnt){
                cout<<-1;
                return 0;
            }
            cout<<anss[cnt-k].second;
        }else{
            if(k>=cnt){
                cout<<-1;
                return 0;
            }
            cout<<anss[cnt-k-1].second;
        }
    }
}
