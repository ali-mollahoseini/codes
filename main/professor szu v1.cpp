///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+

#include <bits/stdc++.h>
//#define ll long long
#define usi unsigned short int
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 10;
const int inf = 0x7FFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;

void solution();
int poshte[MX],head;
bool used[MX];
bool used2[MX];
int n,m;
vector<int> adj[MX];
int mark[MX];

void revdfs(int v){
    used[v] = 1;
    for(auto e: adj[v]){
        if(!used[e]){
            revdfs(e);
        }
    }
    poshte[head++]=v;
}
void rev(int v,int i,int e){
    adj[v].erase(adj[v].begin()+i);
    adj[e].pb(v);
}
void adjrev(int v){
    mark[v]=1;
    int x = adj[v].size();
    int cntr = 0;
    for(int i=0;cntr<x ;){
        cntr++;
        int e = adj[v][0];
        if(used[e]){
            if(!mark[e]){
                adjrev(e);
            }
            rev(v,i,e);
        }else{
            adj[v].erase(adj[v].begin()+i);
        }
    }
}
void dfs(int v){
    used2[v] = 1;
    //cout<<v<<" "<<adj[v].size()<<endl;
    for(auto e :adj[v] ){
        if(used[e]){
            if(!used2[e]){
                mark[v]=36501;
                dfs(e);
            }else if(e==v){
                mark[v]=36501;
            }else{
                mark[v]=min(36501,mark[v]+mark[e]);
            }
        }
    }
}
int32_t main(){
    Init
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[--v].pb(--u);
        if(n >= 400*1000){
            adj[v].shrink_to_fit();
        }
        if(n >= 400*1000){
            adj[u].shrink_to_fit();
        }
    }
    revdfs(n);
    adjrev(n);
    for(int i=0;i<n;i++){
        if(adj[i].capacity()>4){
            adj[i].shrink_to_fit();
        }
    }
    memset(mark , 0,sizeof(mark));
    int cnt =1;
    mark[n]=1;
    while(head){
        int b = poshte[--head];
        if(!used2[b]){
            //cout<<b<<" ";
            dfs(b);
            cnt++;
        }
    }
    //cout<<endl;
    mark[n]=0;
    int mx=0;
    int cntr=0;
    for(int i=0;i<n;i++){
        mx = max(mx, mark[i]);
    }
    if(mx<36500){
        cout<<mx<<endl;
    }else{
        cout<<"zawsze"<<endl;
    }
    for(int i=0;i<n;i++){
        if(mark[i]==mx){
            cntr++;
        }
    }
    cout<<cntr<<endl;
    for(int i=0;i<n;i++){
        if(mark[i]==mx){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}
