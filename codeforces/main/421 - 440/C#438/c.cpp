///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 10 +------------------+ 07 |
///    | 05 |   CF Round 438   | 13 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 100*1000 + 100;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,k;
struct node{
    int a[4];
}inp[MX];
node a;
bool comp(node a, node b){
    if(a.a[0]!=b.a[0]){
        return a.a[0]<b.a[0];
    }else if(a.a[1]!=b.a[1]){
        return a.a[1]<b.a[1];
    }else if(a.a[2]!=b.a[2]){
        return a.a[2]<b.a[2];
    }else if(a.a[3]!=b.a[3]){
        return a.a[3]<b.a[3];
    }
}
bool ok(int a,int b, int c, int d, int n){
    if(a<=n/2 && b<=n/2 && b<=n/2 &&d<=n/2){
        return 1;
    }
    return 0;
}
int32_t main(){
    Init
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>inp[i].a[j];
        }
    }
    bool tf =0;
    sort(inp,inp+n,comp);
    int a[4]={0,0,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            a[j]+=inp[i].a[j];
        }
        tf=tf||ok(a[0],a[1],a[2],a[3],i+1);
    }
    if(tf){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

