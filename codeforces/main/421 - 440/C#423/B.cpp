#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int n,m,r,l,u,d,shoa;
int ar[MX2];
int main(){
    l=inf,u=inf;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<m;j++){
            if(tmp[j]=='B'){
                l=min(l,j);
                u=min(u,i);
                r=max(r,j);
                d=max(d,i);
                cnt++;
            }
        }
    }

    if(cnt==0){
        cout<<1;
        return 0;
    }else if(cnt==1){
        cout<<0;
        return 0;
    }
    shoa=max(abs(r-l)+1,abs(u-d)+1);
    cerr<<shoa<<endl;
    if(shoa<=m&& shoa<=n){
        int sq=shoa*shoa-cnt;
        cerr<<shoa<<" "<<cnt<<endl;
        cout<<sq<<endl;
    }else{
        cout<<-1<<endl;
    }
}
