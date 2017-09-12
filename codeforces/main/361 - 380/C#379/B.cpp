#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int k2,k3,k5,k6;
int main(){
    ll sum=0;
    cin>>k2>>k3>>k5>>k6;
    while(k2&&k5&&k6){
        k2--;
        k5--;
        k6--;
        sum+=256;
    }
    while(k2&&k3){
        k3--;
        k2--;
        sum+=32;
    }
    cout<<sum;
}
