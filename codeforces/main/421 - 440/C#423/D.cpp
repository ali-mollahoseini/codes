//in the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 1000*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;


ll n,k;

int main(){
        cin>>n>>k;
        int ert=(n-1)%k;
        cout<<2*((n-1)/k)+min(2,ert)<<endl;
        for(int i=2;i<=min(1+k,n);i++){
            cout<<1<<" "<<i<<endl;
        }
        for(int i=2;i+k<=n;i++){
            cout<<i<<" "<<i+k<<endl;
        }
}
