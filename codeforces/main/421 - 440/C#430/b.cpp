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
double x;
int r , d , n;
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>d>>r;
    r= d -r;
    cin>>n;
    int cnt=0;
    for(int i=0,u,v ,w;i<n;i++){
        cin>>u>>v>>w;
        v *=v;
        u *=u;
        if((double)sqrt(u+v) - ((double)r + (double)w) >= (double)0 && (double)sqrt(u+v)+(double)w <=(double)d){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

