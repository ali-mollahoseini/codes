//in the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int mod=1000*1000*1000+7;
const int MX=1000+10;
const int lg=30;
const int inf=0x7FFFFFFF;
vector<int> adj[MX];
int par[lg][MX],h[MX];
bool  used[MX];
int par_k(int v, int k){
    for(int i=0;i<lg;i++){
        if(k&(1<<i)){
            v = par[i][v];
        }
    }
    return v;
}
int lca(int u , int v){
    if(h[u]>h[v]){
        swap(u,v);
    }
    v = par_k(v,h[v]-h[u]);
    if(u==v){
        return u;
    }
    for(int i=lg-1;i>=0;i--){
        if(par[i][u] != par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][v];
}
void pre(int n){
    for(int i= 1;i<lg;i++){
        for(int j=0;j<n;j++){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
}
void dfs(int v){
    used[v] = 1 ;
    for(auto u : adj[v]){
        if(!used[u]){
            h[u] = h[v]+1;
            dfs(u);
        }
    }
}
int main(){
    int n,t;
    cin>>t;
    for(int tes=0;tes<t;tes++){
        cin>>n;
        int m;
        for(int i=0;i<n;i++){
            cin>>m;
            for(int  j= 0;j<m;j++){
                int v;
                cin>>v;
                v--;
                adj[v].pb(i);
                adj[i].pb(v);
                par[0][v] = i;
            }
        }
        dfs(0);
        pre(n);
        int q;
        cout<<"Case " << tes+1 << ":"<<endl;
        cin>>q;
        for(int j=0;j<q;j++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            cout<<lca(u,v)+1<<endl;
        }
        for(int i=0;i<MX;i++){
            used[i]=0;
            h[i] = 0;
        }
    }
}
