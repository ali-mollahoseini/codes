//be name khoda
//8)
//;)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
map<int,vector<int> > adj;
int dis[MX1][2],n,x;
bool used[MX1][2];
void dfs(int v,int d,int type){
    used[v][type]=1;
    dis[v][type]=d;
    for(int i=0;i<1LL*adj[v].size();i++){
        if(used[adj[v][i]][type]==0){
            dfs(adj[v][i],d+1,type);
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>x;
    x--;
    for(int i=0;i<n-1;i++){
        int v,u;
        cin>>v>>u;
        v--,u--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(0,0,0);
    dfs(x,0,1);
    int mx0=0;
    for(int i=0;i<n;i++) mx0=max(dis[i][0],mx0);
    //cout<<mx0<<endl;
    if(dis[0][1]==mx0){
        cout<<mx0*2;
    }else{
        int ans=dis[0][1];
        for(int i=0;i<n;i++){
            if(dis[i][0]>dis[i][1]){
                ans=max(ans,dis[i][0]);
            }
        }
        cout<<ans*2<<endl;
    }

}
