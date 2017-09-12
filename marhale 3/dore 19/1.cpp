#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");





int main(){
    ll a=1388;
    for(int i=1;i<2010;i++){
        ll tmp=a;
        tmp*=1388;
        int cntr=1;
        ll zarb=1;
        a=0;
        while(cntr<15){
            a+=((tmp/zarb)%10)*zarb;
            zarb*=10;
            cntr++;
        }
        if(i>2000){
            cout<<i<<" "<<a<<endl;
        }
    }
    int cntr=0;
    ll zarb=1;
    int ans=1;
    while(cntr<6){
        ans*=(a/zarb)%10;
        zarb*=10;
        cntr++;
    }
    cout<<ans;
}
