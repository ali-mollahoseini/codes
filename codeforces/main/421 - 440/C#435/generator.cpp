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

const int MX = 2000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,q;
int inp[MX];

int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=0,a;i<n;i++){
        cin>>a;
        inp[a]=1;
    }
    int ans=0;
    for(int i=0;i<q;i++){
        if(!inp[i]){
            ans++;
        }
    }
    if(inp[q]){
        ans++;
    }
    cout<<ans<<endl;;
}
