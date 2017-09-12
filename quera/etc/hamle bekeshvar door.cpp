///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=100000+100;
const int inf= 0x7FFFFFFF;
using namespace std;
int n, m;
int fst , lst;
int tot[MX1];
map<int, vector<pair<int,int> > > adj;
map<int,vector<int> > smp;
set<int>visited, graph;
int parent[MX1];
int dist[MX1];
bool mark[MX1];

void dijkstra(int v);

int32_t main(){
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m;++i){
        cin >> u >> v >> w;
        adj[--u].pb({--v, w} );
    }
    for(int i=0;i<n;++i){
        dijkstra(i);
    }
    for(int i=0;i<n;i++){
        cout<<tot[i]<<endl;
    }
    return 0;
}
int dfs(int v){
    int ans = 1;
    for(int i=0;i<smp[v].size();i++){
        ans += dfs(smp[v][i]);
    }
    //cout << "ans:" << v << " " << ans << " " << fst << endl;
    if(v != fst){tot[v] += ans - 1 ;}
    return ans;
}
void dijkstra(int v){
    fst = v;
    fill(dist,dist+n,inf);
    //cout << inf << endl;
    fill(mark,mark+n,0);
    fill(parent,parent+n,0);
    parent[v] = -1;
    dist[v]=0;
    graph.insert(v);
    while(visited.size()<graph.size()){
        int ind = -1;
        int mn = inf;
        for(auto e : graph){
            if(!mark[e] && dist[e] < mn){
                mn = dist[e];
                ind = e;
            }
        }
        if(parent[ind] != -1){smp[parent[ind]].pb(ind);}
        mark[ind]  = 1;
        visited.insert(ind);
        //cout<< ind << " " << adj[ind].size() << " ";
        for(int i=0;i<adj[ind].size();i++){
            pair<int,int> pt = adj[ind][i];
            //cout << pt.F << " ";
            if(!mark[pt.F] && dist[ind]+pt.S<dist[pt.F]){
                dist[pt.F] = dist[ind]+pt.S;
                parent[pt.F] = ind;
                graph.insert(pt.F);
            }else if(mark[pt.F] && dist[ind]+pt.S==dist[pt.F]){
                smp[ind].pb(pt.S);
            }
        }
        //cout<<endl;
    }
    dfs(v);
    graph.clear();
    visited.clear();
    smp.clear();
}
