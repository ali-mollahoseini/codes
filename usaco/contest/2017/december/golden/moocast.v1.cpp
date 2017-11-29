//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 1000 + 1000, inf = 0x7FFFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;

ofstream fout("moocast.out");
ifstream fin("moocast.in");
vector<int> ranks,p;
pair<int,int> inp[MX];
struct edge{
    int u , v, w;
};
bool comp (edge a,edge b){
    return a.w < b.w;
}
int mx;
int n;
vector<edge> edges;
void make(int x){
    for(int i=0;i<x;i++){
        p.pb(i);
        ranks.pb(0);
    }
}
int findSet(int x){return (p[x]==x)? x : findSet(p[x]);}
void mergeSet(int x,int y,int w){
    int px = findSet(x),py= findSet(y);
    if(px==py){
        return;
    }
    mx= max(mx,w);
    if(ranks[px]<ranks[py]){
        p[px]=py;
    }else{
        p[py]=px;
        if(ranks[px]==ranks[py]){
            ranks[px]++;
        }
    }
    return;
}
void kruskal(){
    make(n);
    for(int i=0;i<edges.size();i++){
        mergeSet(edges[i].u,edges[i].v,edges[i].w);
        cout<<1<<endl;
    }
}
int32_t main(){
    ios::sync_with_stdio(0);
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>inp[i].F>>inp[i].S;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val = abs(inp[i].F-inp[j].F)*abs(inp[i].F-inp[j].F) + abs(inp[i].S-inp[j].S)*abs(inp[i].S-inp[j].S);
            edges.pb({i,j,val});
        }
    }
    sort(edges.begin(),edges.end(),comp);
    cout<<edges[edges.size()-1].w<<endl;;
    kruskal();
    fout<<mx<<endl;
}
