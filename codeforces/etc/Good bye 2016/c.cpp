//in th name of Allah
#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back

const ll MX1=200*1000+1000;
const ll inf= 0x77FFFFFF;

int main(){
    ll n;
    cin>>n;
    ll a=0,b=inf,c=-inf;
    for(ll i=0;i<n;i++){
        ll d,p;
        cin>>p>>d;
        if(d==1) b=min(b,a);
        if(d==2) c=max(c,a);
        a+=p;
    }
    if(c<=-inf){
        cout<<"Infinity"<<endl;return 0;
    }
    if(c>=b){
        cout<<"Impossible"<<endl;return 0;
    }
    cout<<1899+a-c;

}
