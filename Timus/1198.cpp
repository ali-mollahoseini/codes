///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 04 |    Timus 1198    | 13 |
///    +----+------------------+----+
#include <bits/stdc++.h>

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX = 2000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
int mark[MX];
map<int,vector<int> > adj;
map<int,vector<int> > revadj;
map<int,vector<int> > comp;
vector<int> poshte;
int in[MX];
void dfs(int v);
void revdfs(int v,int col);

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0, u;i<n;i++){
        while(cin >> u && u != 0){
            adj[i].pb(--u);
            revadj[u].pb(i);
        }
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    fill(mark,mark+n, 0);
    int ncom = 1;
    while(poshte.size()){
        int v = poshte.back();
        if(!mark[v]){
            revdfs(v, ncom++);
        }
        poshte.pop_back();
    }
    int ind, cnt=0;
    for(int i=1;i<ncom;i++){
        if(!in[i]){
            cnt++;
            ind = i;
        }
    }
    if(cnt==1){
        sort(comp[ind].begin(),comp[ind].end());
        for(int i=0;i<comp[ind].size();i++){
            cout << comp[ind][i] + 1 << " " ;
        }
        cout << 0 << endl;
    }else{
        cout << 0 << endl;
    }
}

void dfs(int v){
    mark[v] = 1;
    for(int i=0;i<adj[v].size();i++){
        int pt = adj[v][i];
        if(!mark[pt]){
            dfs(pt);
        }
    }
    poshte.pb(v);
}
void revdfs(int v, int col){
    mark[v] = col ;
    comp[col].pb(v);
    for(int i=0;i<revadj[v].size();++i){
        int pt = revadj[v][i];
        if(!mark[pt]){
            revdfs(pt,col);
        }else if(mark[pt] != col) {
            ++in[col];
        }
    }
}
