//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 30000+1000;
typedef pair<int,int> pii;
map<int,vector<int> > adj;
int mark[MX1];
bool dfs(int v, int rng){
    //cout<<1<<endl;
    mark[v]=rng;
    int x = (rng%2)+1;
    //cout<<x<<" "<<rng<<endl;
    bool ok = 1;
    for(int i=0;i<adj[v].size();i++){
        int &pt = adj[v][i];
        if(!mark[pt]){
            ok = (ok & dfs(pt,x));
        }else if(mark[pt]==rng){
            ok=0;
        }
    }
    return ok;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=0, u, v;i<m;++i){
        cin >> u >> v;
        adj[--v].pb(--u);
        adj[u].pb(v);
    }
    bool tf=1;
    for(int i=0;i<n;i++){
        if(!mark[i]){
            tf = tf & dfs(i,1);
        }
    }
    if(tf){
        cout<<"yes"<<endl;
        vector<int>ans;
        for(int  i =0;i<n;i++){
            if(mark[i]==1){
                ans.pb(i+1);
            }
        }
        cout<<ans.size()<<endl;
        for(int  i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"no"<<endl;
    }
}
