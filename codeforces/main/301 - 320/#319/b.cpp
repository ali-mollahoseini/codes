//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int per[MX];
bool mark[MX];
pair<int,int> pa[MX];
vector<int> adj[MX];
int dfs(int u){
    mark[u]=1;
    int cnt=1;
    for(auto v: adj[u]){
        if(!mark[v]){
            cnt+=dfs(v);
        }
    }
    return cnt;
}
int32_t main(){
    Init
    int n ;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>per[i];per[i]--;
        adj[i].pb(per[i]);
    }
    bool tf= 0;
    bool x = 0;
    int cen,cntr=0;
    for(int i=0;i<n;i++){
        if(!mark[i]){
            int sz =dfs(i);
            if(sz==1){
                tf=1;
                cen=i;
            }else if(sz == 2){
                pa[cntr++] = {i,per[i]};
            }else{
                x=1;
            }
        }
    }
    if(x==1 && tf==0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(tf){
        req(i, 0 , n){
            if(i!=cen){
                cout<<cen+1<<' '<<i+1<<endl;
            }
        }
    }else{
        cout<<pa[0].F+1<<' '<<pa[0].S+1<<endl;
        req(i,1,cntr){
            cout<<pa[0].F+1<<' '<<pa[i].F+1<<endl;
            cout<<pa[0].S+1<<' '<<pa[i].S+1<<endl;
        }
    }
}


