//in the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000*1000*1000+7;
const int MX1 = 5*1000*1000+100;
const int MX2 = 2000*1000+100;
const int inf = 2*1000*1000*1000+7;
ll n,x;
ll dp[MX2];
struct voucher{
    ll x;
    ll kind;
    ll len;
    ll cost;
};
bool comp(voucher a,voucher b){
    if(a.x==b.x){
        return a.kind>b.kind;
    }
    return a.x<b.x;
}
voucher vou[MX2];
int main(){
    for(ll i=0;i<MX2;i++){
        dp[i]=inf;
    }
    ios_base::sync_with_stdio(0);
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        ll l,r;
        ll cost;
        cin>>l>>r>>cost;
        vou[i*2].kind=1;
        vou[i*2+1].kind=-1;
        vou[i*2].x=l;
        vou[i*2+1].x=r;
        vou[i*2].len=r-l+1;
        vou[i*2+1].len=r-l+1;
        vou[i*2].cost=cost;
        vou[i*2+1].cost=cost;
    }
    sort(vou,vou+n*2,comp);
    ll mn=inf;
    for(ll i=0;i<2*n;i++){
        if(vou[i].kind==1){
            ll nid=x-vou[i].len;
            if(nid>0){
                //cout<<nid<<" "<<vou[i].cost<<" "<<dp[nid]<<endl;
                mn=min(mn,vou[i].cost+dp[nid]);
            }
        }else{
            dp[vou[i].len]=min(dp[vou[i].len],vou[i].cost);
        }
    }
    if(mn==inf){
        cout<<-1<<endl;
        return 0;
    }
    cout<<mn;
}
