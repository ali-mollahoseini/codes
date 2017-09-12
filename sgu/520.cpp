//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 30000+1000;
typedef pair<int,int> pii;
map<int,vector<int> > adj;
int mark[MX1];
int que[MX1];
int head, tail;
int dis[MX1];
int flag[MX1];///first:(0 not flaged; 1 loose; 2 win;)

bool bfs(int v){
    mark[v]=1;
    que[tail++] = v;
    while(head<tail){
        int tmp = que[head++];
        for(int i=0;i<adj[tmp].size();i++){
            int &pt = adj[tmp][i];
            if(!mark[pt]){
                mark[pt] = 1;
                que[tail++] = pt;
                dis[pt] =  dis[tmp]+1;
            }
        }
    }
}
int32_t main(){
    int n, m;
    cin>>n>>m;
    for(int i=0, u, v;i<m;i++){
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    bfs(0);
    for(int i=head-1;i>-1;--i){
        int tmp = que[i];
        int flg = (dis[tmp]%2+1);
        bool loose = 1;
        for(int  j =0;j<adj[tmp].size();++j){
            int pt = adj[tmp][j];
            if(flag[pt]==1){
                flg=2;
            }
            if(dis[pt]>dis[tmp]){
                if(flag[pt]==1){
                    loose = 0;
                }
                loose &= 1;
            }
        }
        if(loose){
            flag[tmp] = 1;
        }else{
            flag[tmp] = flg;
        }
    }
    if(flag[0]==1){
        cout<<"Nikolay"<<endl;
    }else {
        cout << "Vladimir" << endl;
    }
}
