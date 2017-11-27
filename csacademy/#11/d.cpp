//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
set<int> oks;
int n ,k, m , s;
int dis[MX];
queue<int> q;
void bfs(int v=s-1){
    q.push(v);
    dis[v]=0;
    oks.erase(v);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        int up= min(n-(k-1), tmp+(k-1)), low= max(tmp-(k-1),k-1);
        auto itlow = oks.lower_bound(low);
        auto itup = oks.upper_bound(up);
        for(;itlow!=itup;){
            q.push(*itlow);00
            dis[*itlow] = dis[tmp]+1;
            auto ittmp = itlow;
            itlow++;
            itlow++;
            oks.erase(ittmp);
        }
    }
}
int32_t main(){
    Init
    cin>>n>>k>>m>>s;
    for(int i=0;i<n;i++){
        dis[i]=-1;
        oks.insert(i);
    }
    for(int i=0;i<m;i++){
        int u;
        cin>>u;u--;
        oks.erase(u);
    }
    bfs();
    req(i,0, n)0{
        cout<<dis[i]<<' ';
    }
    cout<<<<endl;
}


