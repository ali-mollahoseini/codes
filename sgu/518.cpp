#include<bits/stdc++.h>

using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define bf push_front
#define F first
#define S second
#define tl ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int MX=1000;
int n,k;
int dp[MX][MX];
map<int,vector<pair<int,int> > > adj;
int lst[MX];
void dfs(int v,int trail){
    dp[v][trail]=1;
    if(trail==k){return ;}
    for(int i=0;i<adj[v].size();i++){
        pair<int,int> pt = adj[v][i];
        if(pt.S == lst[trail] && !dp[pt.F][trail+1]){
            dfs(pt.F,trail+1);
        }
    }
}
int32_t main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0,u; j<n; j++){
            cin>>u;
            if( u){
                adj[i].pb({j,u});
                adj[j].pb({i,u});
                //adj[j].pb({i,u});
            }
        }
    }
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>lst[i];
    }
    dfs(0,0);
    vector<int> todo;
    for(int i=0;i<n;i++){
        if(dp[i][k]){
            todo.pb(i+1);
        }
    }
    cout<<todo.size()<<endl;
    for(int i=0;i<todo.size();++i){
        cout<<todo[i]<<" ";
    }
    cout<<endl;
    return 0;
}
