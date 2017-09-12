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

const int MX = 100 * 1000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
string ans;
vector<pair<int,int> > all;
int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n;
    bool tf=1;
    int cnt=1;
    while(tf){
        tf=0;
        int tmp = cnt*(cnt+1)/2;
        cnt++;
        if(tmp<MX){
            all.pb({tmp,cnt});
            tf=1;
        }
    }
    char c = 'a';
    for(int i=all.size()-1;i>=0;i--){
        while(all[i].F<=n){
            n-=all[i].F;
            for(int j=0;j<all[i].S;j++){
                ans.pb(c);
            }
            c++;
        }
    }
    ans.pb(c);
    cout<<ans<<endl;
}

