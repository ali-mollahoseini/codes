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

const int MX = 200*1000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
int ar[MX];
int inp[MX];
int cur;
vector<int> ans;
bool used[MX];
void nxt(){
    while(ar[cur] || used[cur]){
        cur++;
    }
}
int32_t main(){
    Init
    cin>>n;
    cur = 1;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        ar[inp[i]]++;
    }
    nxt();
    int cntr=0;
    for(int i=0;i<n;i++){
        //cout<<i<<' '<<cur;
        if(ar[inp[i]]>1 && cur<inp[i] ){
            //cout<<1<<endl;
            cntr++;
            ans.pb(cur);
            ar[cur]++;
            ar[inp[i]]--;
            inp[i]=cur;
            used[inp[i]]=1;
            nxt();
        }else if(ar[inp[i]]>1 && !used[inp[i]] && cur>inp[i]){
            //cout<<2<<endl;
            ans.pb(inp[i]);
            ar[inp[i]]--;
            used[inp[i]]=1;
        }else if(ar[inp[i]]==1 && !used[inp[i]]){
            //cout<<3<<endl;
            ans.pb(inp[i]);
            ar[inp[i]]--;
            used[inp[i]]=1;
        }else if(ar[inp[i]]==1 && used[inp[i]]){
            //cout<<4<<endl;
            cntr++;
            ans.pb(cur);
            ar[cur]++;
            nxt();
            ar[inp[i]]--;
            inp[i]=cur;
        }else if(ar[inp[i]]>1){
            cntr++;
            ans.pb(cur);
            ar[cur]++;
            nxt();
            ar[inp[i]]--;
            inp[i]=cur;
        }
    }
    cout<<cntr<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
}

