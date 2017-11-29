///        +--------------------+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 08 +------------------+ 06 |
///    | 29 |UC 2015 January 3 | 07 |
///    +----+------------------+----+

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 1000 * 1000 + 1000;
const int inf = 0x7FFFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("grass.out");
ifstream fin("grass.in");
int n , m;
int mark[MX];
map<int,vector<int> > adj;
map<int,vector<int> > revadj;
map<int,vector<int> > comp;
map<int,vector<int> > DAG[2];
vector<int> poshte;
vector<int> poshte2;
int dp[MX][2];//0:norm, 1: rev;
int in[MX][2];
bool used[MX][2];
int cntr;
inline void dfs(int v);
inline void revdfs(int v,int col);
void topo(int v, int t){
    if(in[v][t]){return ;}
    used[v][t]=1;
    for(auto e : DAG[t][v]){
        int fU = comp[e].size();
        if((ll) dp[e][t] < (ll) dp[v][t] + fU){
            dp[e][t] = dp[v][t] + fU;
        }
        in[e][t]--;
        if(!in[e][t]){
            topo(e,t);
        }
    }
    poshte2.pb(v);
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fin >> n >> m;
    for(int i=0,u , v;i<m;i++){
        fin >> u >> v;
        adj[--u].pb(--v);
        revadj[v].pb(u);
    }
    for(int i = 0;i<n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    fill(mark,mark+MX,0);
    int cnt = 1;
    while(poshte.size()){
        int ind = poshte.back();
        if(!mark[ind]){
            revdfs(ind,cnt);
            cnt++;
            //cout<<cnt<<endl;
        }
        poshte.pop_back();
    }
    for(int i=0;i<cnt;i++){
        for(int j = 0 ;j<2;j++){
            dp[i][j] = -inf;
        }
    }
    int x = mark[0];
    int cx = comp[x].size();
    dp[x][0]=cx;
    dp[x][1]=cx;
    for(int i=0;i<2;i++){
        for(int j=0;j<cnt;j++){
            if(!in[j][i] &&!used[j][i]){
                topo(j,i);
            }
        }
    }
    int mx = 0;
    for(auto e: DAG[0]){
        int f =  e.F;
        for(int i=0;i<e.S.size();i++){
            cntr++;
            int pt = e.S[i];
            mx = max(mx, dp[pt][0]+dp[f][1]-cx);
        }
    }
    fout << mx <<endl;
}

inline void dfs(int v){
    mark[v] = 1;
    for(int i=0;i<adj[v].size();i++){
        int pt = adj[v][i];
        if(!mark[pt]){
            dfs(pt);
        }
    }
    poshte.pb(v);
}

inline void revdfs(int v, int col){
    mark[v] = col ;
    comp[col].pb(v);
    for(int i=0;i<revadj[v].size();++i){
        int pt = revadj[v][i];
        if(!mark[pt]){
            revdfs(pt,col);
        }else if(mark[pt] < col) {
            DAG[0][mark[pt]].pb(col);
            in[col][0]++;
            DAG[1][col].pb(mark[pt]);
            in[mark[pt]][1]++;
        }
    }
}
