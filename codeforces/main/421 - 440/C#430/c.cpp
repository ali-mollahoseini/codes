///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 08 +------------------+ 05 |
///    | 29 |   CF Round 430   | 07 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 2*100*1000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int a[MX];
map<int,vector<int> > adj;
int dp[MX];
int rea[MX];
int mn[MX];
int n;

bool mark[MX];
void dfs(int v){
    mark[v]=1;
    for(int i=0;i<adj[v].size();i++){
        int pt = adj[v][i];
        if(!mark[pt]){
            dp[pt] = max(rea[v],__gcd(dp[v],a[pt]));
            rea[pt] = __gcd(rea[v],a[pt]);
            dfs(pt);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0, u, v;i<n-1;i++){
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    dp[0]=a[0];
    rea[0]= a[0];

    dfs(0);
    for(int i=0;i<n;i++){
        cout<< dp[i] <<" ";
    }
    cout<<endl;
}

