//in the name of Allah

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
//ofstream fout ("butter.out");
const int MX1 = 3*1000*100+1000;
int n, m;
int  inp[MX1];
int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n >> m;
    int ans=-1;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        if(inp[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=0, u , v;i<m;i++){
        cin>>u>>v;
        u--;v--;
        if(inp[u] && inp[v]){
            cout<<1<<endl;
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
