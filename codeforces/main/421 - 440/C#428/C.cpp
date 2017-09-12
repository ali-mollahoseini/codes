//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX1 = 100*1000+1000;
ll n;
ll que[MX1];
ll dis[MX1];
vector<ll> adj[MX1];
ll head, tail;
bool mark[MX1];
vector<int> ans;
void bfs(int v){
    que[tail++] = v;
    mark[v]=1;
    while(head<tail){
        ll tmp = que[head++];
        int cntr=0;
        for(int i=0;i<adj[tmp].size();i++){
            ll pt = adj[tmp][i];
            if(!mark[pt] && ){
                cntr++;
                mark[pt]=1;
                que[tail++] = pt;
                dis[pt]=dis[tmp]+1;
            }
        }
        if(!cntr){ ans.push_back(tmp);}
    }
}
int main(){
    cin>>n;
    for(ll i=0, u, v;i<n-1;i++){
        cin>>u >> v;
        u--;v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bfs(0);
    double out=0;
    ll sum=0;
    for(int i=0;i<ans.size();i++){
        sum+=dis[ans[i]];
    }
    cout<<setprecision(15)<<fixed;
    if(ans.size()==0||sum==0){
        cout<< 0<<endl;
        return 0;
    }
    //cout<<ans.size();
    out= (double)sum/(double)ans.size();
    cout<<out<<endl;
}
