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

const int MX = 70000 + 100;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
map<int,bool> ex;
int32_t main(){
    Init
    cin>>n;
    int mx=0;
    int cur = 0;
    for(int i=0;i<n;i++){
        char mode;int ri;
        cin>>mode>>ri;
        if(mode=='-'){
            if(ex[ri]){
                ex[ri]=0;
                cur--;
            }else{
                ex[ri]=0;
                mx++;
            }
        }else{
            cur++;
            ex[ri]=1;
            mx = max(mx,cur);
        }
    }
    cout<<mx<<endl;
}

