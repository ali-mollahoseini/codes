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

const int MX = 100*1000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n, m, k;
int ans[2];
int r[MX], l[MX];
int32_t main(){
    Init
    cin>>n>>m>>k;
    ans[0] = (m+(k-1))/k-1;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    int last=0, lastr=0;
    for(int i=0;i<n;i++){
        if(lastr<l[i]-1){
            last = l[i]-1;
        }
        if(last+k<=r[i]){
            last = last+k;
            ans[1]++;
            //cout<<last<<endl;
            ans[1]+=((r[i]-last))/k;
            last+=(((r[i]-last))/k)*k;
        }
        lastr =r[i];
    }
    cout<<ans[1]<<' '<<ans[0]<<endl;
}

