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
#degfine Init ios::sync_with_stdio(0),cin.tie(0);

const int MX = 2000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
multiset<int>;
int poww(int a , int b){
    int ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}
int add(int l ,int r,int x){
    int tool=9;
    int cnt=0;
    while(cnt<l){
        x=x%poww(10,tool);
        tool--;
        cnt++;
    }
    while(r<tool){
        x/=10;
        tool--;
    }
    return x;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){

    }
}

