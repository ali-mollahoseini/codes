#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n,ar[1000];
set<ll> s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        ar[i]--;
    }
    for(int i=0;i<n;i++){
        ll fst=i;
        ll nx=ar[i];
        ll cntr=0;
        bool tf=1;
        while(cntr<=n && tf){
            if(nx==fst){
                tf=0;
            }else{
                nx=ar[nx];
            }
            cntr++;
        }
        if(tf==0){
            if(cntr%2==0){
                s.insert(cntr/2);
            }else{
                s.insert(cntr);
            }
        }else{
            cout<<-1;
            return 0;
        }
    }
    ll mul=1,gcd=1;
    for(auto p : s){
        mul=mul*p/__gcd(mul,p);
    }
    cout<<mul;
}
