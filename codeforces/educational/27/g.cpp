//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX1 = 10*1000;
using namespace std;
int n, m;
map<int, vector<pair<int ,int> > > adj;
int dis[MX1];
void dfs(int v ){
    //ut<<dis[0]<<endl;
    for(int i=0 ;i<adj[v].size();i++){
        pair<int,int> pt = adj[v][i];
        //cout<<dis[pt.F]<<" "<< (dis[v]^pt.S) <<endl;
        if((dis[v]^pt.S)<dis[pt.F]){
            dis[pt.F] = dis[v]^pt.S;
            dfs(pt.F);
        }
    }
}
int32_t main(){
    cin>>n>>m;

    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        adj[--u].pb({--v,w});
        adj[v].pb({u,w});
    }
    fill(dis,dis+MX1,inf);
    dis[0]=0;
    dis[0]^adj[0][1].S;

    dfs(0);
    cout<<dis[n-1];
    return 0;
}
