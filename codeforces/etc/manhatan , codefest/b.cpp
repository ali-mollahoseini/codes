///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 19 |   CF Round 434   | 28 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 100000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,p,q,r,dp[3][MX];
int inp[MX];
int32_t main(){
    Init
    int x=0;
    cin>>n>>p>>q>>r;
    x+= p+q+r;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    dp[0][0]=inp[0]*p;
    for(int i=1;i<n;i++){
        dp[0][i]=max(p*inp[i],dp[0][i-1]);
    }
    dp[1][0]=inp[0]*p+inp[0]*q;
    for(int i=1;i<n;i++){
        dp[1][i]=max(dp[1][i-1],dp[0][i]+inp[i]*q);
    }
    dp[2][0]=inp[0]*p+inp[0]*q+inp[0]*r;
    for(int i=1;i<n;i++){
        dp[2][i]=max(dp[2][i-1],dp[1][i]+inp[i]*r);
    }
    cout<<dp[2][n-1]<<endl;;
}

