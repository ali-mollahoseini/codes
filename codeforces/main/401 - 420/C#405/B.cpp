#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll inf=0x7FFFFFFF;
const ll MX1=200*1000+1000;


ll n,m;
vector<ll> adj[MX1];
bool used[MX1];


pair<ll,ll> dfs(ll v){
    used[v]=1;
    ll cntr=0;
    ll nodes=0;nodes++;
    pair<ll,ll> tmp;
    cntr+=adj[v].size();
    for(ll i=0;i<adj[v].size();i++){
        if(used[adj[v][i]]==0){
            tmp= dfs(adj[v][i]);
            nodes+=tmp.second;
            cntr+=tmp.first;
        }
    }
    return {cntr,nodes};
}
int main(){
    ios_base::sync_with_stdio(0);
    bool tf=1;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(ll i=0;i<n;i++){
        if(used[i]==0){
            pair<ll,ll> tmp=dfs(i);
            if(tmp.second*(tmp.second-1)!=tmp.first){
                tf=0;
                break;
            }
        }
    }
    if(tf){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

//define funcs
