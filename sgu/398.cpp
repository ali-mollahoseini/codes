
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
vector<int> ans;
int bfs(int v){
    mark[v]=1;
    que[head++] = v;
    par[v]=-1;
    while(tail<head){
        int tmp= que[tail++],dcur= dis[tmp];
        if(dcur==2){break;}
        for(int i=0;i<adj[tmp].size();i++){
            if(mark[adj[tmp][i]]==0){
                mark[adj[tmp][i]]=1;
                dis[adj[tmp][i]] = dis[tmp]+1;
                que[head++] = adj[tmp][i];
                if(dcur==1){ans.pb(adj[tmp][i]);}
            }
        }
    }
}
int32_t main(){
    int n,e;
    cin>>n>>e;
    for(int i=0,u,v;i<e;i++){
        cin>>u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int x;
    cin>>x;
    x--;
    bfs(x);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}
