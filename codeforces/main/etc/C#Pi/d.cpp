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

const int MX = 2*100*1000 + 100;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,k,a,m;
set<int> hits;
set<int> hits2;
int32_t main(){
    Init
    cin>>n>>k>>a>>m;
    int curmx = (n-a)/(a+1)+1;
    hits.insert(0);
    hits.insert(n+1);
    hits2.insert(0);
    hits2.insert(-(n+1));
    for(int i =0;i<m;i++){
        int u;
        cin>>u;
        auto itl = hits2.lower_bound(-u);
        auto itr = hits.upper_bound(u);
        int l = abs(*itl), r= *itr;
        //cout<<l<<' '<<r<<' '<<curmx<<endl;
        int f= (r-l-1);
        if(f>=a){
            f= (f-a)/(a+1)+1;
            int s= (max(0LL,(r-u-1-a))/(a+1)+max(0LL,(u-l-1-a))/(a+1));
            if((r-u-1)>=a){
                s++;
            }
            if((u-l-1)>=a){
                s++;
            }
            curmx-=f-s;
            if(curmx<k){
                cout<<i+1;
                return 0;
            }
        }
        hits.insert(u);
        hits2.insert(-u);
    }
    cout<<-1<<endl;
}

