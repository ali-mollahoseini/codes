#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll m,b,mxd,sum,x,y,hei,wid;
ll ban(ll w,ll h){

    ll tmp=(w+1)*w/2;
    ll sum=(tmp+(tmp+h*(w+1)))*(h+1)/2;
    return sum;
}
int main(){
    cin>>m>>b;
    x=m*b;
    y=b;
    ll mx=0;
    for(int i=0;i<b+1;i++){
        //cout<<b-i<<" "<<i*m<<" "<<ban(b-i,i*m)<<endl;
        mx=max(mx,ban(b-i,i*m));
    }
    cout<<mx;
}
