#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;

ll n,k;

int main(){
    cin>>n>>k;
    ll a=n/k;
    if(a%2==0){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
}
