///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 5 * 1000 * 1000+10;
const int base = 727;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string s;
int pre[MX],suf[MX],pw[MX], n, dp [MX];
bool is_palindrome(int r){
     int v1 = pre[r],v2 =(suf[n]- suf[n-r]*pw[r]%mod +mod)%mod;
     return v1 == v2;
}
int32_t main(){
    Init
    cin>>s;
    n = s.size();
    pw[0]=1;
    for(int i=0;i<n;i++){
        pw[i+1] = (pw[i]*base)%mod;
        pre[i+1] = (pre[i]*base%mod+s[i])%mod;
        suf[i+1] = (suf[i]*base%mod+s[n-i-1])%mod;
    }
    int ans = 0;
    for(int i=1;i<n+1;i++){
        if(is_palindrome(i)){
            dp[i] = dp[i/2]+1;
            ans += dp[i];
        }
    }
    cout<<ans<<endl;
}


