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

const int MX = 70000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int a,b,f,k;
int32_t main(){
    Init
    a=a;
    cin>>a>>b>>f>>k;
    if(b-f<0||b-(a-f)<0 ){
        cout<<-1<<endl;
        return 0;
    }else if(k>1 && b-(a-f)*2<0){
        cout<<-1<<endl;
        return 0;
    }else if(k>2 &&b-(f)*2<0){
        cout<<-1<<endl;
        return 0;
    }
    int cntr=0;
    int cur=b;
    int mod=0;
    int dis[2]={f,a-f};
    while(k){
        if(cur>=a+dis[!mod] ||(cur>=a &&k==1)){
            cur-=a;
            //cout<<k<<endl;
        }else{
            cur=b-dis[!mod];
            cntr++;
        }
        k--;
        mod=!mod;
    }
    cout<<cntr<<endl;
}

