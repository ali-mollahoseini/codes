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

const int MX = 1000*1000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7,pw = 1<<18;
using namespace std;
int n,x;
int used[MX];
int32_t main(){
    Init
    cin>>n>>x;
    int ans =0;
    if(n==2 && x==0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n==1){
        cout<<x<<endl;
        return 0;
    }
    if(n==2){
        cout<<x<<' '<< 0<<endl;
        return 0;
    }
    for(int i=0;i<n-3;i++){
        cout<<i<<' ';
        ans^=i;
    }
    cout<<(pw/2)+ans<<' '<<pw+x<<' '<<pw+(pw/2)<<endl;
}

