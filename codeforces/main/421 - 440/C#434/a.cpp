///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 17 |   CF Round 434   | 26 |
///    +----+------------------+----+

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
//#define Init ios::sync_with_stdio(0);

const int MX = 2000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,k;
int32_t main(){
    //Init
    cin>>n>>k;
    int cnt5=0,cnt2=0;
    int tmp = n;
    while(tmp%5==0){
        tmp/=5;
        cnt5++;
    }
    while(tmp%2==0){
        tmp/=2;
        ++cnt2;
    }
    while(cnt2<cnt5&&cnt2<k){
        n*=2;
        cnt2++;
    }
    while(cnt5<cnt2 &&cnt5<k){
        n*=5;
        cnt5++;
    }
    while(cnt2<k &&cnt5==cnt2){
        n*=10;
        cnt2++;
        cnt5++;
    }
    cout<<n<<endl;
}

