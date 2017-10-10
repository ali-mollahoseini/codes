#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
const int mod=1000*1000*1000+7;
const int MX=100+10;
const int inf=0x7FFFFFFF;
const int lg=30;
int n,m;
vector<int> adj[MX];
vector<pair<int,int> > adjmst[MX];
int treew;
struct edges{
    int id,u,v,c,dis;
}edge[MX];
bool mark[MX];
int h[MX];
int par[lg][MX];
int setn[MX];
int dp[lg][MX];
bool comp (edges a, edges b){return a.dis<b.dis;}
vector<int> dsu[MX];
int par_k(int v, int k){
    for(int i=0;i<lg;i++){
        if(k&1<<i){
            v= par[i][v];
        }
    }
    return v;
}
int lca(int u ,int v){
    if(h[u]>h[v]){
        swap(u,v);
    }
    v= par_k(v,h[v]-h[u]);
    if(u==v){
        return u;
    }
    for(int i = lg-1;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}
int miz(int v ,int k){
    int mx=0;
    for(int i=0;i<lg;i++){
        if(k&1<<i){
            mx= max(mx, dp[i][v]);
            v = par[i][v];
        }
    }
    return v;
}
void dfs(int v){
    mark[v] = 1;
    for(auto u: adjmst[v]){
        if(!mark[u.F]){
                h[u.F]=h[v]+1;dp[0][u.F]=u.S; par[0][u.F] =v;
                dfs(u.F);
        }
    }
}
void pre(){
    for(int i=1;i<lg;i++){
        for(int j=0;j<n;j++){
            par[i][j] = max(par[i-1][j],par[i-1][par[i-1][j]]);
        }
    }
}
void merg(int u,int v){
    if(dsu[u].size()>dsu[v].size()){
        swap(u,v);
    }
    while(dsu[u].size()){
        setn[dsu[u].front()] = v;
        dsu[v].pb(dsu[u].front());
        dsu[u].pop_back();
    }
}
void kruskal(){
    sort(edge,edge+m,comp);
    for(int i=0;i<n;i++){
        setn[i]= i;
        dsu[i].pb(i);
    }
    for(int i=0;i<m;i++){
        int u=edge[i].u, v = edge[i].v, w =edge[i].dis;
        if(setn[u]!= setn[v]){
            adjmst[u].pb({v,w});
            adjmst[v].pb({u,w});
            treew+=w;
            merg(setn[u],setn[v]);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edge[i].dis;
    }
    for(int i=0;i<m;i++){
        cin>>edge[i].c;
    }
    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;
        u--;v--;
        edge[i].u=u;
        edge[i].v=v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    kruskal();
    dfs(0);
    pre();
    for(int i=0;i<n;i++){

    }
}
