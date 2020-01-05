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
int ar[200];
int a[3];
int32_t main(){
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0,u,v;i<3;i++){
        cin>>u>>v;
        for(int j=u;j<v;j++){
            ar[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<101;i++){
        ans+= a[ar[i]-1]*ar[i];
    }
    cout<<ans;
}

