///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 08 +------------------+ 05 |
///    | 29 |   CF Round 430   | 07 |
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
int l,r ,x,y ;
double n;
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>l>>r>>x>>y>>n;
    if((x*n<=r && x*n>=l)||(y*n<=r && y*n>=l) || (floor(r/n)>=x && (floor(r/n))/n<=y&&floor(r/n)*n>=l) || (ceil((l)/n)>=x && ceil((l)/n<=y))&&ceil((l)/n)*n<=y){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

