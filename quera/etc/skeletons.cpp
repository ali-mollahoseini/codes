#include <bits/stdc++.h>
#define F first
#define int long long
#define S second
#define pb push_back
#define rep(i,val,x) for(int i=val;i<x;i++)
#define Init ios::sync_with_stdio(0);

const int MX = 1000*100+100,MX1 = 1000*1000+100,inf = 0x7FFFFFFF,mod = 1e9+7,lg = 30;
using namespace std;
vector<int> adj[MX];
vector<int> revadj[MX],comp[MX];
bool mark[MX];
vector<int> stk;
void dfs(int u){
    mark[u]=1;
    for(auto v: adj[u]){
        if(!mark[v])
            dfs(v);
    }
    stk.pb(u);
}
void revdfs(int u, int col){
    mark[u]=1;
    comp[col].pb(u);
    for(auto v: revadj[u]){
        if(!mark[v]){
            revdfs(v,col);
        }
    }
}
int neibcntr[MX];
int lsth[MX];
int gozar=0;
void primity(int v=0, int deph=0){
    if(mark[v]){
        if(gozar){
            gozar = __gcd(gozar,deph%gozar-lsth[v]%gozar+gozar);
        }else{
            gozar = deph - lsth[v];
        }
    }else{
        mark[v]=1;
        lsth[v] =deph;
    }
    while(neibcntr[v]<adj[v].size()){
        primity(adj[v][neibcntr[v]++],deph+1);
    }
}
int32_t main(){
    int n, m;
    while(cin>>n>>m &&(n||m)){
        fill(mark,mark+MX,0);
        rep(i,0,n){
            neibcntr[i]=0;
            lsth[i]=0;
            gozar=0;
            adj[i].clear();
            revadj[i].clear();
        }
        rep(i, 0, m){
            int u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            revadj[v].pb(u);
        }
        rep(i,0,n){
            if(!mark[i]){
                dfs(i);
            }
        }
        fill(mark,mark+MX,0);
        int cnt=0;
        while(!stk.empty()){
            int tmp  = stk.back();
            stk.pop_back();
            if(!mark[tmp]){
                revdfs(tmp,cnt);
                cnt++;
            }
        }
        fill(mark,mark+MX,0);
        bool tf=1;
        //cout<<cnt<<endl;
        if(cnt>1){
            tf = 0;
        }
        if(!tf){
            cout<<"N"<<endl;
            continue;
        }
        primity();
        if(tf && gozar==1){
            cout<<"Y"<<endl;
        }else{
            cout<<"N"<<endl;
        }
    }
}
