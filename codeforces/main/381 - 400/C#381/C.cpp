#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n,m;
ll ar[MX2];
int main(){
    cin>>n>>m;
    int mn=inf;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mn=min(mn,b-a+1);
    }
    cout<<mn<<endl;
    for(int i=0;i<n;i++){
        cout<<i%mn<< " " ;
    }
    cout<<endl;
    return 0;
}
