#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000;
ll n,a,b,c;
int main(){
    cin>>n>>a>>b>>c;
    ll ans=0;
    if(n%4==3){
        ans=min(min(a,b+c),c*3);
    }else if(n%4==1){
        ans=min(min(c,b+a),a*3);
    }else if(n%4==2){
        ans=min(min(b,c*2),a*2);
    }
    cout<<ans;
}
