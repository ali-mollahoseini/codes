///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 19 |   CF Round 434   | 28 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 1000*100 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7,pw = 1<<18;
using namespace std;
int n, m, k,x;
bool mark[MX];
map<int,vector<int> >adj;
int dfs(int v, int lim);
int ddfs(int v, int lim);
int dddfs(int v, int lim);
int dfs(int v, int lim){
    mark[v]=1;
    int ans=1;
    int tmp=0;
    for(auto e: adj[v]){
        if(!mark[e]){
            tmp+=(dfs(e,lim))%mod;
            mark[e]=0;
        }
        tmp%=mod;
    }
    cout<<tmp<<endl;
    ans += (tmp*(k-1))%mod;
    ans%=mod;
    if(lim<x){
        tmp =0;
        for(auto e: adj[v]){
            if(!mark[e]){
                tmp+=(ddfs(e,lim+1))%mod;
                mark[e]=0;
            }
            tmp%=mod;
        }
        ans += (tmp*1ll)%mod;
        ans%=mod;
    }
    tmp =0;
    for(auto e: adj[v]){
        if(!mark[e]){
            tmp+=(dddfs(e,lim))%mod;
            mark[e]=0;
        }
    }
    cout<<tmp<<endl;
    ans += (tmp*(m-k))%mod;
    return ans;
}
int ddfs(int v,int lim){
    mark[v] = 1;
    int ans=1;
    int tmp=0;
    for(auto e: adj[v]){
        if(!mark[e]){
            tmp+=(dfs(e,lim))%mod;
            mark[e]=0;
        }
        tmp%=mod;
    }
    ans += (tmp*(k-1))%mod;
    ans%=mod;
    tmp =0;
    return ans;
}
int dddfs(int v,int lim){
    mark[v] = 1;
    int ans=1;
    int tmp=0;
    for(auto e: adj[v]){
        if(!mark[e]){
            tmp+=(dfs(e,lim))%mod;
            mark[e]=0;
        }
        tmp%=mod;
    }
    ans += (tmp*(k-1))%mod;
    ans%=mod;
    tmp =0;
    for(auto e: adj[v]){
        if(!mark[e]){
            tmp+=(ddfs(e,lim))%mod;
            mark[e]=0;
        }
    }
    ans += (tmp*(m-k))%mod;
    ans%=mod;
    return ans;
}
int32_t main(){
    Init
    cin>>n>>m;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    cin>>k>>x;
    int ans= dfs(0,0);
    cout<<ans<<endl;
}

