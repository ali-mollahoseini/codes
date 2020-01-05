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

const int MX = 70000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int a[4], miz[4];
void rotat(){
    int b[4];
    for(int i=0;i<4;i++){
        b[i]= a[i];
    }
    for(int i=0;i<4;i++){
        a[i]=b[(i+1)%4];
    }
}
int32_t main(){
    Init
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    int pcur=0;//nafar chandom
    while(1 == 1){
        if(!a[0] || !a[1] || !a[2] || !a[3]){
            break;
        }
        a[pcur]--;
        rotat();
        miz[pcur]++;
        pcur=(pcur+1)%4;
    }
    cout<<miz[0]<<' '<<miz[1]<<' '<<miz[2]<<' '<<miz[3];
}

