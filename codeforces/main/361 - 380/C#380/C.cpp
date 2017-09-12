#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+100;
const int inf=0x7FFFFFFF;
ll n,k,s,t;
ll gas[MX2];
pair<ll,ll> pv[MX2];
bool ok(ll v){
    ll sum=0;
    ll f=0;
    for(ll i=0;i<k+1;i++){
        if(gas[i]-f>v){
            return 0;
        }else{
            //cout<<min((gas[i]-f),v-(gas[i]-f))<<endl;
            sum+=min((gas[i]-f),v-(gas[i]-f));
            sum+=2*((gas[i]-f)-min((gas[i]-f),v-(gas[i]-f)));
            f=gas[i];
        }
    }
    //cout<<"sum : "<<sum<<endl;
    if(sum<=t){
        return 1;
    }else {
        //cout<<"ze"<<endl;
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>s>>t;
    for(ll i=0;i<n;i++){
        cin>>pv[i].second>>pv[i].first;
    }
    for(ll i=0;i<k;i++){
        cin>>gas[i];
    }
    gas[k]=s;
    sort(gas,gas+k+1);
    ll first=1;
    ll last=2000*1000*1000;
    while(first<last){
        ll mid=(first+last)/2;
        if(ok(mid)){
            last=mid;
        }else{
            first=mid+1;
        }
    }
    //cout<<first;
    ll ans=inf;
    sort(pv,pv+n);
    for(ll i=0;i<n;i++){
        if(pv[i].first>=first){
            ans=min(pv[i].second,ans);
        }
    }
    if(ans==inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
