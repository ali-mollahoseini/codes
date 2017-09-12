#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=2000+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int inp[MX1], out[MX1];
int num[MX1];
bool used[MX1];
bool mark[MX1];
int main(){
    int n, m;
    cin>>n>>m;
    int ans= n/m;
    int md= n%m;
    int chngs=0;
    int cntr=0;
    int oks=0;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        if(inp[i]<=m){
            num[inp[i]]++;
            if(num[inp[i]]>ans && !used[inp[i]]){
                used[inp[i]]=1;
                oks++;
            }
        }
    }
    //cout<<oks<<endl;
    md -= oks;
    //cout<<md<<endl;
    for(int i=1;i<m+1;i++){
        if(num[i]<=ans)continue;
        mark[i]=1;
        int tmp= ans+ (md>=0);
        for(int j=0;j<n;++j){
            if(inp[j]==i&&num[i]>tmp){
                num[i]--;
            }else if(inp[j]==i){
                out[j]=i;
            }
        }
        md += md<0;
    }
    for(int i=1;i<m+1;++i){
        if(mark[i])continue;
        mark[i]=1;
        int tmp = ans;
            //cout<<i<<endl;
        for(int j=0;j<n;j++){
            //cout<<"ok"<<endl;
            //cout<<(inp[j]>m)<< " " << (mark[inp[j]]) <<endl;
            if(inp[j]==i){
                out[j]=i;
            }else if(num[i]<tmp && inp[j]>m && !out[j]){
                num[i]++;
                out[j]=i;
                chngs++;
            }else if(num[i]<tmp && !out[j] && mark[inp[j]]){
                num[i]++;
                out[j]=i;
                chngs++;
            }
        }
    }
    cout<<ans<<" "<<chngs<<endl;
    for(int i=0;i<n;++i){
        if(out[i]==0){out[i]=inp[i];}
        cout<<out[i]<<" ";
    }
    cout<<endl;

}
