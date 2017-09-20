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

const int MX = 100000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,m;
vector<int> adj[MX];
int cnt[2];
bool col[MX],used[MX];
void dfs(int v,int c){
    used[v] = 1;
    col[v] = c;
    cnt[c]++;
    for(auto e: adj[v]){
        if(!used[e]){
            dfs(e,!c);
        }
    }
}
int32_t main(){
    Init
    cin>>n;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    dfs(0,0);
    cout<<1ll*cnt[0]*cnt[1]-1ll*(n-1);
}

