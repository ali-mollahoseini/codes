///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 07 |
///    | 25 |   CF Round 436   | 03 |
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
int n ,a[MX];
int mn[MX];
int mx[MX];

int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mx[0]= a[n-1] - a[0];
    mn[0]= a[1] - a[0];
    mx[n-1]= mx[0];
    mn[n-1]= a[n-1] - a[n-2];
    for(int i =1;i<n-1;i++){
        mn[i]= min(a[i]-a[i-1],a[i+1]-a[i]);
        mx[i]= max(a[n-1]-a[i],a[i]-a[0]);
    }
    for(int i=0;i<n;i++){
        cout<<mn[i]<<' '<<mx[i]<<endl;
    }
}

