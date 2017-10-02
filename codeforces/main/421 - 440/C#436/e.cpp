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

const int MX = 2000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,mx;
struct product{
    int ind,d,p,t;
}inp[102];
struct{
    vector<int> s;
    int miz;
}dp[MX];
vector<int>ans;
bool com(product a,product b){
    return a.d<b.d;
}
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i].t>>inp[i].d>>inp[i].p;
        inp[i].ind = i;
        inp[i].d--;
    }
    sort(inp,inp+n,com);
    for(int i=0;i<n;i++){
        for(int j =inp[i].d;j>=inp[i].t;j--){
            int pt = j-inp[i].t;
            if(dp[j].miz<dp[pt].miz+ inp[i].p){
                dp[j].miz = dp[pt].miz+ inp[i].p;
                dp[j].s = dp[pt].s;
                dp[j].s.pb(inp[i].ind);
            }
            if(mx<dp[j].miz){
                mx = dp[j].miz;
                ans = dp[j].s;
            }
        }
    }
    //sort(ans.begin(),ans.end());
    cout<<mx<<endl<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<' ';
    }
    cout<<endl;
}

