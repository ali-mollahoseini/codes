//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define pc(x) __builtin_popcount(x)
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX =18,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int dp[1<<MX][MX], vw[MX],mat[MX][MX],n,m,k,mx;
int32_t main(){
    Init
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>vw[i];
            dp[1<<i][i]=vw[i];
            mx =max(dp[1<<i][i],mx);
    }
    for(int i=0;i<k;i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        mat[u][v]=w;
    }
    int x =(1<<n);
    for(int i=0;i<x;i++){
        if(pc(i)<=m &&pc(i)>1){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(int k =0;k<n;k++){
                        if(i&(1<<k)&&k!=j){
                            dp[i][j]= max(dp[i][j],dp[i^(1<<j)][k]+mat[k][j]+vw[j]);
                        }
                    }
                    mx =max(dp[i][j],mx);
                }
            }
        }
    }
    cout<<mx<<endl;
}


