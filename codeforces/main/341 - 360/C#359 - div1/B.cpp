//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 3*1000*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int sub[MX],n,q;
vector<int> adj[MX];
int p[MX];
int ans[MX];
set<pair<int,int> >  dfs(int u){
    set<pair<int,int> > ret;
    for(auto v:adj[u]){
        auto tmp = dfs(v);
        sub[u]+=sub[v];
        if(tmp.size()>ret.size()){
            swap(tmp,ret);
        }
        for(auto e: tmp){
            ret.insert(e);
        }
    }
    ret.emplace(sub[u],u);
    ans[u] = ret.lower_bound({(sub[u]+1)/2,0})->S;
    return ret;
}
int32_t main(){
    Init
    cin>>n>>q;
    sub[0]=1;
    for(int i=1;i<n;i++){
        sub[i]=1;
        cin>>p[i];
        p[i]--;
        adj[p[i]].pb(i);
    }
    dfs(0);
    for(int i=0;i<q;i++){
        int v;
        cin>>v;
        cout<<ans[v-1]+1<<endl;
    }
}


