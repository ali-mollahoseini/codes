//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x7F7FFFFF;
const int MX1 = 17000;
using namespace std;
map<int,vector<int> > adj;
bool mark[MX1];
int que[MX1];
int head, tail;
int par[MX1];
int dis[MX1];
int bfs(int v){
    mark[v]=1;
    que[head++] = v;
    par[v]=-1;
    while(tail<head){
        int tmp= que[tail++];
        for(int i=0;i<adj[tmp].size();i++){
            if(mark[adj[tmp][i]]==0){
                mark[adj[tmp][i]]=1;
                par[adj[tmp][i]] = tmp;
                dis[adj[tmp][i]] = dis[tmp]+1;
                que[head++] = adj[tmp][i];
            }
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int fst,snd;
    cin>>fst>>snd;
    bfs(fst);
    vector<int> path;
    int tmp= dis[snd];
    cout<<tmp<<endl;
    path.pb(snd);
    int x=par[snd];
    while(tmp--){
        path.pb(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
