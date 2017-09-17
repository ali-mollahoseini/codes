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
int  n,k;
int32_t main(){
    cin>>n>>k;
    int mn=inf, mx=-inf;
    if(k<n && k>0){
        mn= 1;
    }else if(k==0 || k==n){
        mn = 0;
    }
    if(n/3<k){
        mx = n-k;
    }else{
        mx = k*2;
    }
    cout<<mn<<" "<<mx<<endl;
}
