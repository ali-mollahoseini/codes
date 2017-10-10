//in the name of Allah
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
const int MX=200*1000+1000;
const int inf= 0x7FFFFFFF;
const int lg = 30;
using namespace std;
int n,m;
vector<pair<int,int> > adj[MX];
vector<pair<int,pair<int,int> > > edges;
vector<pair<int,pair<int,int> > > krus;
vector<pair<int,int>> adjt[MX];
int treew;
int h[MX];
int mx[MX];
bool mark[MX];
pair<int,int>par[lg][MX];//f:mx ,s:v;
int setn[MX];
vector<int> ozv[MX];
int par_k(int v, int k){
    for(int i=0;i<lg;i++){
        if(k & 1<<i){
            v = par[i][v].S;
        }
    }
    return v;
}
int miz(int v, int k){
    int mx=0;//f:mx,s:v
    for(int i=0;i<lg;i++){
        if(k & 1<<i){
            mx= max(mx,par[i][v].F);
            v = par[i][v].S;
        }
    }
    return mx;
}
int lca(int u,int v){
    if(h[u]>h[v]) swap(u,v);
    v = par_k(v,h[v]-h[u]);
    if(u==v) return u;
    for(int i=lg-1;i>=0;i--){
        if(par[i][v].S!=par[i][u].S){
            v = par[i][v].S;
            u = par[i][u].S;
        }
    }
    return par[0][v].S;
}
void pre(){
    for(int i=1;i<lg;i++){
        for(int j=0;j<n;j++){
            par[i][j].F = max(par[i-1][j].F, par[i-1][par[i-1][j].S].F);
            //cout<<par[i][j].F<<endl;
            par[i][j].S = par[i-1][par[i-1][j].S].S;
        }
    }
}
void dfs(int v){
    mark[v] = 1;
    for(auto u: adjt[v]){
        if(!mark[u.F]){
           par[0][u.F].S=v;h[u.F]=h[v]+1;par[0][u.F].F=u.S;
           dfs(u.F);
        }
    }
}
void merg(int u, int v){
    if(ozv[u].size()> ozv[v].size()){
        swap(u,v);
    }
    while(ozv[u].size()){
        ozv[v].pb(ozv[u].back());
        setn[ozv[u].back()] = v;
        ozv[u].pop_back();
    }
    ozv[u].clear();
}
void kruskal(){
    sort(krus.begin(),krus.end());
    for(int i=0;i<n;i++){
        setn[i]=i;
        ozv[i].pb(i);
    }
    for(int i=0;i<m;i++){
        int u = krus[i].S.F,v = krus[i].S.S ,w = krus[i].F;
        if(setn[u]!=setn[v]){
            adjt[u].pb({v,w});
            adjt[v].pb({u,w});
            treew+=w;
            merg(setn[u],setn[v]);
        }
    }
}
int32_t main(){
    cin.tie();ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        --u;--v;w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        edges.pb({w,{u,v}});
        krus.pb({w,{u,v}});
    }
    kruskal();
    dfs(0);
    pre();
        //cout<<treew<<endl;
    for(int i =0;i<m;i++){
        int u = edges[i].S.F ,v=  edges[i].S.S, w = edges[i].F;
        int lcaa= lca(u,v);
        int mx = max(miz(u,h[u]-h[lcaa]),miz(v,h[v]-h[lcaa]));
        //cout<<mx<<' '<<w<<' '<<lcaa<<endl;
        cout<<treew-mx+w<<endl;
    }
}
