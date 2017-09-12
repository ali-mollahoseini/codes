#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

ll tarkib(int r,int n){
    int ar[n-r],ar1[n-r];
    for(int i=0;i<n-r;i++){
        ar[i]=i+r+1;
        ar1[i]=i+1;
    }
    for(int i=0;i<n-r;i++){
        for(int j=0;j<n-r;j++){
            int x=__gcd(ar[i],ar1[j]);
            ar[i]/=x;
            ar1[j]/=x;
        }
    }
    ll ans=1;
    for(int i=0;i<n-r;i++){
        ans*=ar[i];

    }
    return ans;
}

int main(){
    ll x=tarkib(40,80);
    cout<<x;
}
