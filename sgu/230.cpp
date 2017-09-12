///in the name of Allah
///ALi Mollahoseini
#include <bits/stdc++.h>

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 200;
int n, m;
map<int,vector<int> >adj;
vector<int >todo;
bool mark[MX1];
int in[MX1];
void dfs(int v){
    todo.pb(v);
    mark[v]=1;
    for(int i=0;i<adj[v].size();++i){
        int pt = adj[v][i];
        --in[pt];
        if(!mark[pt] && !in[pt]){
            dfs(pt);
        }
    }
}
int32_t main(){
    cin>>n>> m;
    for(int i = 0, u, v;i<m;++i){
        cin >> u >> v;
        adj[--u].pb(--v);
        in[v]++;
    }
    bool tf = 1;
    while(tf){
        tf=0;
        for(int i=0;i<n;++i){
            if(!mark[i] &&  !in[i]){
                dfs(i);
                tf=1;
            }
        }
    }
    if(todo.size()<n){
        cout<<"No solution"<<endl;
    }else {
        int out[todo.size()+10];
        for(int i=0;i<todo.size();i++){
             out[todo[i]]=i+1;
        }
        for(int i=0;i<todo.size();i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
    }
}
