//in the name of Allah
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x7FFFFFFA;
const int MX = 1000 * 100 + 2;
using namespace std;
queue<int> q;
vector<int> adj[MX];
int d[MX],n,m;
int sz[MX];
void bfs(){
    while(!q.empty()){
        int f = q.front();q.pop();
        for(int i=0;i<sz[f];i++){
            if(d[adj[f][i]]>d[f]+1){
                q.push(adj[f][i]);
                d[adj[f][i]] = d[f]+1;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<n-1;i++){
        scanf("%d%d",&u,&v);
        d[i+1]=inf;
        adj[--u].pb(--v);
        adj[v].pb(u);
        ++sz[v];++sz[u];
    }
    q.push(0);
    bfs();
    for(int i=0,t,v;i<m;i++){
        scanf("%d %d",&t,&v);
        --v;
        if(t==1){
            q.push(v);
            d[v]=0;
        }else{
            bfs();
            printf("%d\n",d[v]);
        }
    }
}
