///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 15 |   CF Round 431   | 24 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100*1000 + 10;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
map<int,vector<int> > adj;
bool mark[MX];
int color[MX];
bool cyc;
int n , m;
int tcol[2];
void dfs(int v,int c){
    tcol[c]++;
    color[v] = c;
    mark[v] = 1;
    c=!c;
    for(auto e : adj[v]){
        if(!mark[e]){
            dfs(e,c);
        }else if(color[e]==color[v]){
            cyc=1;
        }
    }
    return;
}
int32_t main(){
    Init
    int ans=2;
    cin>>n>>m;
    if (m==0){ans =3;}
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        --v;--u;
        if(adj[v].size() || adj[u].size()){
            ans = 1;
        }
        adj[u].pb(v);
        adj[v].pb(u);
        //cout<<u<<' '<<v<<endl;
    }
    int one=0;
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i,0);
            one+= 1ll*tcol[0]*(tcol[0]-1)/2 + 1ll*tcol[1]*(tcol[1]-1)/2;
            tcol[0]=0;tcol[1]=0;
        }
    }
    if(cyc){ans = 0;}
    if(ans==0){
        cout<<ans<<' '<<1<<endl;
    }else if(ans==1){
        cout<<ans<<' '<<1ll*one<<endl;
    }else if(ans==2){
        cout<<ans<<' '<<1ll*m*(n-2);
    }else if(ans==3){
        cout<<ans<<' '<<1ll*n*(n-1)*(n-2)/6;
    }
}
