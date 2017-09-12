#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1= 500*1000+100;
const int MX2= 2*1000+100;
const ll inf=0x7FFFFFFFFFFFFFFF;
int n,s,ar[MX1];
int sum[2];
vector<pair<int,int> > pa;//f:sum 1 to i ;s:sum a1 to an;
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        sum[0]+=i+1;
        sum[1]+=ar[i];
        pa.push_back({sum[0],sum[1]});
    }
    int ans=0,mx=0;
    for(int i=0;i<n;i++){
        if(pa[i].first*(i+1)+pa[i].second<=s){
            mx=pa[i].first*(i+1)+pa[i].second;
            ans=i+1;
        }
    }
    cout<<ans<<" "<<mx;
}
