
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000;
int n,k,d,t;
int main(){
    cin>>n>>t>>k>>d;
    int ans= (n+k-1)/k*t;
    if(d+t<ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
