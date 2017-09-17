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
bool p[10000];
int n;
int32_t main(){
    ios::sync_with_stdio(0);
    cin>> n;
    int a,b;
    for(int i=1;i<n;i++){
        if(__gcd(i,n)==1&&i<n-i){
            a = i;
            b = n-i;
        }
    }
    cout<<a << " "<<b;
}

