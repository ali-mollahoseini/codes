///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 04 |     UVa 3670     | 13 |
///    +----+------------------+----+
#include <bits/stdc++.h>

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
map<string ,set<string> > adj;
map<string ,set<string> > revadj;
map<int ,set<int> > compadj;
map<int ,vector<string> > comp;
map<string ,int > mark;
vector<string> poshte;
bool used[400];
vector<int> ind;
int in[400];
int miz;

void adjprocess(string v, string lst);
void dfs(string v);
void revdfs(string v,int col);
void reset();

void dfscomp(int v){
    if(used[v]==1){return ;}
    used[v]=1;
    ind.pb(v);
    miz += comp[v].size();
    for(auto e : compadj[v]){
        if(!used[e]){
            dfscomp(e);
        }
    }
}
int32_t main(){
    Init
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            string aj;
            getline(cin,aj);
            adjprocess(s,aj);
        }
        for(auto e : adj){
            if(!mark[e.F]){
                dfs(e.F);
            }
        }
        mark.clear();
        int col = 1;
        while(poshte.size()){
            string tmp = poshte.back();
            if(!mark[tmp]){
               revdfs(tmp,col++);
            }
            poshte.pop_back();
        }
        for(int i = 1;i<col;i++){
            if(comp[i].size()>1){
                dfscomp(i);
            }
        }
        cout << miz <<endl;
        vector<string> ans;
        for(int i=0 ;i<ind.size();i++){
            for(auto e: comp[ind[i]]){
                ans.pb(e);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<< ans[i] ;
            if(i+1 != ans.size()){cout<< " ";}
        }
        cout<<endl;
        reset();
    }
}

void adjprocess(string v, string lst){
    int f=1;
    if(lst[lst.size()-1]!=' '){
        lst.pb(' ');
    }
    for(int i=1;i<lst.size();i++){
        if(lst[i] == ' '){
            adj[v].insert(lst.substr(f,i-f));
            revadj[lst.substr(f,i-f)].insert(v);
            f = i+1;
        }
    }
}

void dfs(string v){
    mark[v] = 1;
    for(auto e : adj[v]){
    if(!mark[e]){
            dfs(e);
        }
    }
    poshte.pb(v);
}

void revdfs(string v,int col){
    mark[v]=col;
    comp[col].pb(v);
    for(auto e : revadj[v]){
        if(!mark[e]){
            revdfs(e,col);
        }else if(mark[e]<col){
            compadj[mark[e]].insert(col);
            in[col]++;
        }
    }
}

void reset(){
    poshte.clear();
    adj.clear();
    revadj.clear();
    comp.clear();
    mark.clear();
    compadj.clear();
    ind.clear();
    fill(used,used+400,0);
    fill(in,in+400,0);
    miz = 0;
}
