///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 10 +------------------+ 07 |
///    | 05 |   CF Round 438   | 13 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 100*1000 + 100;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
vector<pair<int,int> > adj[2][MX];//0:adj, 1: rev;
vector<pair<int,pair<int,int> > > adjspfa[MX];//0:adj, 1: rev;
int dp[2][MX];
int prev[2][MX];
void dijkstra(int v, int ind){
    priority_queue<pair<int,int>,vector<pair<int,int> >,> pq;
    bool mark[MX];
    for(int i=0;i<n;i++){
        dp[ind][i]=inf;
        mark[i]=inf;
    }
    dp[ind][v]=0;
    pq.push({0,v});
    while(!pq.empty()){
        int u = pq.top().S,dist = pq.top().F  ;
        pq.pop();
        if(mark[u]){continue;}
        dp[ind][u]=dis;
        for(auto v:adj[ind][u]){
            if(dp[ind][v.F]>dp[ind][u]+v.S){
                pq.push({dp[ind][u]+v.S,v.F});
            }
        }
    }
}
int32_t main(){
    Init
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        adj[0][u].pb(v);
        adj[1][v].pb(u);
    }
    dijsktra(s,0);
    dijsktra(t,1);
    int cntr=0;
    for(int i=0;i<n;i++){
        for(auto v :adj[0][i]){
            if(dp[0][i] + dp[1][v.F]+ v.S == dp[0][t]){
                adjspfa[i].pb({v.F,{v.S,cntr});
                adjspfa[i].pb({v.F,{v.S,cntr});
                cntr++;
            }
        }
    }
    for(int i=0;i<n;i++){

    }
}

