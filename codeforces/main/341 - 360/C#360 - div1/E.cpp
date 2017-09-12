///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 5 * 1000 + 10;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
//variables..............
int n,m;
int is[MX];
int mark[MX];
vector<int>adj[MX],revadj[MX],comp[MX],compadj[MX];
vector<int> poshte;
//funcs.........
void solution();

int32_t main(){
    Init
    solution();
}
void dfs(int v){
    mark[v]=1;
    for(auto pt:adj[v]){
        if(!mark[pt]){
            dfs(pt);
        }
    }
    poshte.pb(v);
}
void revdfs(int v, int col){
    mark[v] = col;
    comp[col].pb(v);
    for(auto pt : revadj[v]){
        if(!mark[pt]){
            revdfs(pt,col);
        }
    }
}

queue<int> q;
int dis[MX];
int bfs(int v){
    int ans=inf;
    memset(dis,0,sizeof(dis));q.push(v);dis[v]=1;
    while(q.size()){
        int tmp = q.front();q.pop();
        for(auto pt:adj[tmp]){
            if(!dis[pt]){
                dis[pt] = dis[tmp]+1;
                q.push(pt);
            }else if(pt == v){
                ans= min(dis[tmp],ans);
            }
        }
    }
    return ans;
}

int mnCycle(int v){
    int mn=inf;
    for(auto pt:comp[v]){
        mn = min(mn,bfs(pt));
    }
    return mn;
}

int scc(){
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    memset(mark,0,sizeof(mark));
    int cnt=1;
    while(poshte.size()){
        int tmp = poshte.back();
        poshte.pop_back();
        if(!mark[tmp]){
            revdfs(tmp,cnt);
            cnt++;
        }
    }
    fill(is,is+MX,1);
    for(int i=0;i<n;i++){
        for(auto e:adj[i]){
            if(mark[i]!=mark[e]){
                is[mark[i]]=0;
            }
        }
    }
    return cnt;
}
void solution(){
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[--u].pb(--v);
        revadj[v].pb(u);
    }
    int nc = scc();
    int sum=0;
    int cntr=0;
    for(int i=1;i<nc;i++){
        if(comp[i].size()!=1&&is[i]){
            int mn = mnCycle(i);
            sum += mn;
            cntr++ ;
        }
    }
    int ans = 998*sum + n + cntr;
    cerr<<sum<<" "<<n<<" "<<cntr<<endl;
    cout<<ans<<endl;
}
