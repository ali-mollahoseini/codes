//in the name of Allah
#include <bits/stdc++.h>
#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX1 = 1000*1000+10;
using namespace std;
vector<pair<ll,ll > > v;
ll ar[MX1],righ[MX1], lef[MX1];
int main(){
    Init;
    ll n;
    std::cin>>n;
    for(ll i=0;i<n;i++){
        lef[i] = -1LL;
        righ[i] = n;
    }
    v.clear();
    for(ll i=0;i<n;i++){
        cin>>ar[i];
            //cout<<1<<std::endl;
        while(v.size()&&ar[i]<v.back().F){
            righ[v.back().S]=i;
            v.pop_back();
        }
        v.pb({ar[i],i});
    }
    v.clear();
    for(ll i=n-1;i>-1;i--){
        while(v.size()&&ar[i]<=v.back().F){
            lef[v.back().S]=i;
            v.pop_back();
        }
        v.pb({ar[i],i});
    }
    ll mn=0;
    for(ll i=0;i<n;i++){
        //cerr<<i<<" "<<abs(righ[i]-i)*abs(lef[i]-i)*ar[i]<<endl;
        mn+=(ll)abs(righ[i]-i)*abs(lef[i]-i)*ar[i];
    }




    v.clear();
    for(ll i=0;i<n;i++){
        lef[i]=-1;
        righ[i]=n;
    }
    for(ll i=0;i<n;i++){
        while(v.size()&&ar[i]>v.back().F){
            righ[v.back().S]=i;
            v.pop_back();
        }
        v.pb({ar[i],i});
    }
    v.clear();
    for(ll i=n-1;i>-1;i--){
        while(v.size()&&ar[i]>=v.back().F){
            lef[v.back().S]=i;
            v.pop_back();
        }
        v.pb({ar[i],i});
    }
    ll mx=0;
    for(ll i=0;i<n;i++){
        mx+=(ll)abs(righ[i]-i)*abs(lef[i]-i)*ar[i];
    }
    cerr<<mn<<" "<<mx;
    ll ans= mx-mn;
    cout<<ans<<endl;
}
