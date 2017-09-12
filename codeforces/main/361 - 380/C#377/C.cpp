#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=8*1000*1000+100;
const int MX2= 2*1000+100;
const ll inf=0x7FFFFFFFFFFFFFFF;

ll a,b,c;
ll anss[10];
int main(){
    cin>>a>>b>>c;
    ll mx=max(a,max(b,c));
    ll ans=inf;
    anss[0]=abs(a-mx)+abs(b-mx)+abs(c-mx);
    anss[1]=abs(a-1-mx)+abs(b-1-mx)+abs(c-mx);
    anss[2]=abs(a-1-mx)+abs(b-mx)+abs(c-mx);
    anss[3]=abs(a-mx)+abs(b-mx)+abs(c-mx);
    anss[4]=abs(a-mx)+abs(b-1-mx)+abs(c-mx);
    anss[5]=abs(a-mx)+abs(b-1-mx)+abs(c-1-mx);//
    anss[6]=abs(a-mx)+abs(b-(mx-1))+abs(c-mx);//
    anss[7]=abs(a-mx)+abs(b-mx)+abs(c-mx);//
    anss[8]=abs(a-mx)+abs(b-mx)+abs(c-1-mx);//
    for(int i=0;i<9;i++){
        if(anss[i]<ans){
            //cout<<anss[i]<<" "<<i<<endl;
            ans=anss[i];
        }
    }
    cout<<ans;
}
