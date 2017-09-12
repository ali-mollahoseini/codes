///in the name of Allah
///ALi Mollahoseini
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 10000+1000;
typedef pair<int,int> pii;
map<int,vector<pair<int,int> > > adj;
int dis[MX1];
bool mark[MX1];
int out[MX1];
int mxp=0;
void dfs(int v){
    mark[v]=1;
    for(int i=0;i<adj[v].size();i++){
        pair<int,int> &pt = adj[v][i];
        if(!mark[pt.F]){
            dis[pt.F]= dis[v]+pt.S;
            out[pt.F]= max(dis[pt.F], out[pt.F]);
            dfs(pt.F);
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    int ind = 0;
    int mx = 0 ;
    for(int i=1, p, w;i<n;i++){
        cin>> p >> w;
        adj[--p].pb({i,w});
        adj[i].pb({p,w});
        dis[i]= dis[p] + w;
        out[i]= max(dis[i], out[i]);
        if(mx<dis[i]){
            mx=dis[i];
            ind=i;
        }
    }
    for(int i=0;i<n;i++){dis[i]=0;}
    dfs(ind);
    mx=0;
    for(int i=0;i<n;i++){
        if(mx<dis[i]){
            mx = dis[i];
            ind = i;
        }
        mark[i]=0;
        dis[i]=0;
    }
    dfs(ind);
    for(int i=0;i<n;i++){
        cout<<out[i]<<endl;
    }
}
