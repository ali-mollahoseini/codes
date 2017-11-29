//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 200*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int val[MX], n,k;
bool mark[MX];
vector<int> adj[MX];
void dfs(int u){
    mark[u]=1;
    for(auto v: adj[u]){
        if(!mark[v]){
            dfs(v);
            val[u]+=val[v];
        }
    }
}
int32_t main(){
    Init
    cin>>n>>k;
    req(i, 0 , k*2){
        int x;
        cin>>x;
        val[--x]++;
    }
    req(i, 0 , n-1){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    int sum=0;
    req(i, 0, n){
        sum+=min(val[i],2*k-val[i]);
    }
    cout<<sum<<endl;
}


