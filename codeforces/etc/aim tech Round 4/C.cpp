#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n,m,k;
int sum;
bool visited[MX2];
int cntr;
set<int> st;
map<int,int> col;
int c[MX2];
vector<int> adj[MX2];
void dfs(int v){
    if(visited[v]==1){return;}
    visited[v]=1;
    col[c[v]]++;
    cntr++;
    for(int i=0;i<adj[v].size();i++){
        if(visited[adj[v][i]]==0){
            dfs(adj[v][i]);
        }
    }
    return;
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<m;i++){
        int l, r;
        cin>>l>>r;
        adj[l-1].push_back(r-1);
        adj[r-1].push_back(l-1);
    }
    for(int i=0;i<n;i++){
        if (!visited[i]){

            dfs(i);
            int mx=0;
            for(map<int,int>::iterator pii=col.begin();pii !=col.end();pii++){
                mx=max(mx,pii->second);
            }
            sum+=cntr-mx;
            col.clear();
            cntr=0;
        }
    }
    cout<<sum;
}
