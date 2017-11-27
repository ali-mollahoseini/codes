//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 1000*100 + 1000, inf = 1000*1000*1000+1,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("lasers.out");
ifstream fin("lasers.in");
map<int,int> mp;
int n;
pair<int,int> arr[2];
vector<int> adj[MX];
queue<int> q;
int dis[MX];
bool mark[MX];
void bfs(){
}
int32_t main(){
    ios::sync_with_stdio(0);
    fin>>n;
    int cntr=1;
    for(int i=0;i<2;i++){
        fin>>arr[i].F>>arr[i].S;
        arr[i].S+=inf;
        if(!mp[arr[i].F]){
            mp[arr[i].F]=cntr++;
        }
        arr[i].F=mp[arr[i].F];
        if(!mp[arr[i].S]){
            mp[arr[i].S]=cntr++;
        }
        arr[i].S=mp[arr[i].S];
    }
    for(int i=0;i<n;i++){
        int x, y;
        fin>>x>>y;
        y+=inf;
        if(!mp[y]){
            mp[y]=cntr++;
        }
        y=mp[y];
        if(!mp[x]){
            mp[x]=cntr++;
        }
        x=mp[x];
        adj[x].pb(y);
        adj[y].pb(x);
    }
    q.push(arr[0].F);
    q.push(arr[0].S);
    dis[arr[0].F]=0;
    dis[arr[0].S]=0;
    mark[arr[0].F]=1;
    mark[arr[0].S]=1;
    while(!q.empty()){
        int u = q.front();q.pop();
        int d = dis[u];
        for(auto v : adj[u]){
            if(!mark[v]){
                mark[v]=1;
                dis[v]=d+1;
                q.push(v);
            }
        }
    }
    if(mark[arr[1].F] || mark[arr[1].S]){
        if(mark[arr[1].F]&& mark[arr[1].S]){
            fout<<min(dis[arr[1].F],dis[arr[1].S])<<endl;
        }else if(mark[arr[1].F]){
            fout<<dis[arr[1].F]<<endl;
        }else if(mark[arr[1].S]){
            fout<<dis[arr[1].S]<<endl;
        }
    }else{
        fout<<-1<<endl;
    }
}
