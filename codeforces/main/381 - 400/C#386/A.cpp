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
    cin>>a>>b>>c;
    int ans=0;
    while(a>0&&b>1&&c>3){
        a--;
        b-=2;
        c-=4;
        ans+=7;
    }
    cout<<ans;
}
