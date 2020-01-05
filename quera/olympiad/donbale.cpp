#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int MX = 2e5 + 1;
struct node{
    int id, k, s;
}co[MX];
int inp[MX];
int dp[MX];
int ans[MX];
bool comp(node a, node b){
    if(a.k==b.k){
        if(a.s%a.k == b.s%b.k)
            return a.s < b.s;
        return a.s%a.k < b.s%b.k;
    }
    return a.k < b.k;
}
int32_t main(){
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>inp[i];
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>co[i].s>>co[i].k;
        co[i].s--;
        co[i].id = i;
    }
    sort(co,co+q,comp);
    for(int i=0;i<q;i++){
        //cout<<"id "<<co[i].id<<endl;
        if(i &&  co[i].k == co[i-1].k && co[i].s%co[i].k == co[i-1].s%co[i-1].k){
            ans[co[i].id] = dp[co[i].s];
            continue;
        }
        int s = co[i].s, k = co[i].k;
        int cur = (n-s)/k*k+s;
        while(cur>=s){
            dp[cur] = dp[cur + k] + inp[cur];
            cur-=k;
        }
        ans[co[i].id] = dp[co[i].s];
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
}
