
#include <bits/stdc++.h>
//#define ll long long
#define pb push_back
#define F first
#define S second
#define Init ios::sync_with_stdio(0);

using namespace std;
typedef long long ll;

const int mod=1000*1000*1000+7, MX=1000*100+10,inf=0x7FFFFFFF;
bool mark[MX];
int par[MX],m,n;
bool ans =1;
vector<int> adj[MX];
bool cycle(int u){
    mark[u]=1;
    for(auto v: adj[u]){
        if(mark[v] &&par[u]!=v){
            ans =0;
        }else if(!mark[v]){
            par[v]=u;
            cycle(v);
        }
    }
}
int main(){
    Init
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(!mark[i]){
            ans=1;
            cycle(i);
            sum+=ans;
        }
    }
    cout<<sum<<endl;
}
