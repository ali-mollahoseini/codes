///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1 = 100 * 1000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;

map<int, vector<pair<int, int > > >adj;
pair<int,pair<int, int> >  edges[MX1];
int n, m;
bool mark[1100];
void prim(int v);
int32_t main(){
    cin >> n >> m;
    for(int i=0, u, v, w;i<m;++i){
        cin >> u >>  v >> w;
        adj[--u].pb({--v, w});
        adj[v].pb({u, w});
    }
    prim(0);
}
void prim(int v){
    int ans=0;
    set<pair<int,int> > st;
    int cur=v;
    mark[v]=1;
    for(int i=0;i<n-1;++i){
        for(int i=0;i<adj[cur].size();i++){
            int pt = adj[cur][i].F;
            if(!mark[pt]){
                st.insert({adj[cur][i].S, pt});
            }
        }
        int ind;
        int mn=inf;
        for(auto e : st){
            if(!mark[e.S]){
                mn= e.F;
                ind = e.S;
                break;
            }
        }
        st.erase(st.find({mn,ind}));
        mark[ind]=1;
        ans+=mn;
        cur = ind;
    }
    cout<<ans<<endl;
}
