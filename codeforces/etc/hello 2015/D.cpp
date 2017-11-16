//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 4*1000*100 + 1000,inf = 1e18,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
struct query{
    int x,y;
    int type;
}qu[MX];

int q;
vector<int> adj[MX],radj[MX];
map<int,int>mp;
int mark[MX],comp[MX];
stack<int>stk;

void add(int x, int y,int type){
    if(type==1){
        adj[x^1].pb(y^1);
        adj[y].pb(x);

        adj[x].pb(y);
        adj[x^1].pb(y^1);
    }else{
        adj[x^1].pb(y);
        adj[y^1].pb(x);

        adj[x].pb(y^1);
        adj[y].pb(x^1);
    }
}
void dfs(int u){
    mark[u]=1;
    for(auto v:adj[u]){
        radj[v].pb(u);
        if(!mark[v]){
            dfs(v);
        }
    }
    stk.push(u);
}
void rdfs(int u,int col){
    comp[u]=col;
    for(auto v:radj[u]){
        if(!comp[v]){
            rdfs(v,col);
        }
    }
}
bool sat(int n){
    n++;
    int cntr=2;
    req(i , 0 , n){
        int x,y;
        if(mp[qu[i].x]){
            x=mp[qu[i].x];
        }else{
            x=mp[qu[i].x]=cntr;
            cntr+=2;
        }
        if(mp[qu[i].y+inf]){
            y=mp[qu[i].y+inf];
        }else{
            y=mp[qu[i].y+inf]=cntr;
            cntr+=2;
        }
        add(x,y,qu[i].type);
    }
    //cout<<1<<endl;
    req(i,2,cntr){
        if(!mark[i]){
            dfs(i);
        }
    }
    int cnt=1;
    while(!stk.empty()){
        int tmp = stk.top();stk.pop();
        if(!comp[tmp]){
            rdfs(tmp,cnt++);
        }
    }
    mp.clear();
    req(i,0,cntr){
        mark[i]=0;
        adj[i].clear();
        radj[i].clear();
    }
    bool tf=1;
    for(int i=2;i<cntr;i+=2){
        if(comp[i]==comp[i^1]){
            tf=0;
        }
        comp[i]=0;
        comp[i^1]=0;
    }
    return tf;
}
int  bin(){
    int l =0,r =q;
    while(l<r){
        int m = (l+r)/2;
        if(sat(m)){
            l=m+1;
        }else{
            r=m;
        }
    }
    return r;
}
int32_t main(){
    Init
    cin>>q;
    req(i,0,q){
        int a, b;
        cin>>qu[i].x>>qu[i].y>>a>>b;
        qu[i].type=a*b;
    }
    int ans = bin();
    req(i,0,ans){
        cout<<"Yes"<<endl;
    }
    req(i,ans,q){
        cout<<"No"<<endl;
    }

}


