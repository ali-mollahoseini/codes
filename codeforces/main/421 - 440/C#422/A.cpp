//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int a,b;
int ar[MX1][MX1];
//////bool ar[MX1][MX1];
int main(){
    cin>>a>>b;
    ll ans=1;
    for(int i=2;i<=min(a,b);i++){
        ans*=i;
    }
    cout<<ans;
}
