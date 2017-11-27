//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7,lg=30;
using namespace std;
vector<int> adj[MX];
vector<int> top10[MX];
vector<int> top[lg][MX];
int par[lg][MX],h[MX];
int n , m , q;
vector<int> ans;
bool mark[MX];
int par_k(int v,int k){
    for(int i=lg;i+1;i--){
        if(k&(1<<i)){
            vector<int> tmp= ans;
            ans.clear();
            merge(tmp.begin(),tmp.end(),top[i][v].begin(),top[i][v].end(),ans.begin());
            while(ans.size()>10){
                ans.pop_back();
            }
            v= par[i][v];
        }
    }
    return v;
}
void lca(int u,int v){
    if(h[u]>h[v]){
        swap(u,v);
    }
    v= par_k(v,h[v]-h[u]);
    if(v==u){
        return ;
    }
    for(int i=lg;i+1;i--){
        if(par[i][v]!=par[i][u]){
            vector<int> tmp,tmp2;
            merge(top[i][v].begin(),top[i][v].end(),top[i][u].begin(),top[i][u].end(),tmp.begin());
            merge(tmp.begin(),tmp.end(),ans.begin(),ans.end(),tmp2.begin());
            ans =tmp;
            while(ans.size()>10){
                ans.pop_back();
            }
            v= par[i][v];
            u= par[i][u];
        }
    }
    vector<int> tmp = ans;
    ans.clear();
    merge(tmp.begin(),tmp.end(),top[0][v].begin(),top[0][v].end(),ans.begin());
}
void dfs(int u){
    mark[u]=1;
    for(auto v: adj[u]){
        if(!mark[v]){
            h[v]=h[u]+1;
            par[0][v]=u;
            merge(top10[u].begin(),top10[u].end(),top10[v].begin(),top10[v].end(),top[0][v].begin());
            cout<<1<<endl;
            while(top[0][v].size()>10){
                top[0][v].pop_back();
            }
            dfs(v);
        }
    }
}
void add(int v, int val){
    top10[v].pb(val);
    sort(top10[v].begin(),top10[v].end());
    if(top10[v].size()>10){
        top10[v].pop_back();
    }
}
void pre(){
    for(int i=1; i<lg;i++){
        req(j,0,n){
            par[i][j]= par[i-1][par[i-1][j]];
            merge(top[i-1][j].begin(),top[i-1][j].end(),top[i-1][par[i-1][j]].begin(),top[i-1][par[i-1][j]].end(),top[i][j].begin());
            while(top[i][j].size()>10){
                top[i][j].pop_back();
            }
        }
    }
}
int32_t main(){
    Init
    cin>>n>>m>>q;
    req(i,0,n-1){
        int u , v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    req(i,0,m){
        int a;
        cin>>a;
        add(a,i+1);
    }
    h[0]=0;
    dfs(0);
    pre();
    req(i,0,q){
        int u, v,a;
        cin>>u>>v>>a;
        lca(u,v);
        int x = ans.size();
        int k = min(0خخ ئو,a);
        cout<<k<<' ';
        for(int i=0;i<k;i++){
            cout<<ans[i]<< ' ';
        }
        cout<<endl;
        ans.clear();
    }
}


