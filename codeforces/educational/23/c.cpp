//be name khoda
//8)
//;)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

int32_t main(){
    ll n,s;
    cin>>n>>s;
    s+=(9-s%9)%9;
    ll tmp=s;
    ll mn=1e18;
    mn--;
    ll cntr=0;
    while(mn>s){
        mn/=10;
    }
    //cout<<s<<endl;;
    ll ans=0;
    tmp=s;
    while(mn>0){
        ans+=(tmp)/mn;
        tmp-=(tmp/mn)*mn;
        //cout<<tmp<<endl;
        mn/=10;
        ans*=10;
    }
    //cout<<ans<<endl;
    if(ans<=n){
        cout<<n-ans+1<<endl;
    }else{
        cout<<0<<endl;
    }
}
