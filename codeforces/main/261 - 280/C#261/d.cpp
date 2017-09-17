//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX = 1000*1000+10;
using namespace std;
int n ;
pair<int,int> inp[MX];
multiset<int> st;
map<int,int> mp;
int f[2][MX];///f[0]:1-i, f[1]:j-n;
int add(){
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>n;
    for(int i=0,u;i<n;i++){
        cin>>u;
        inp[i].F = u,inp[i].S = i;
        mp[u]++;
    }
    sort(inp,inp+n);
    int lst=-1,cnt;
    for(int i=0;i<n;i++){
        if(inp[i].F == lst){
            cnt++;
        }else{
            cnt=1;
            lst = inp[i].F;
        }
        f[0][inp[i].S]=cnt;
        f[1][inp[i].S]=mp[inp[i].F]-cnt+1;
        st.insert(f[0][inp[i].S]);
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        auto it = st.find(f[0][i]);
        st.erase(it);
        ans += distance(st.upper_bound(f[1][i]),st.end());
        cout<<st.end()-it<<endl;
    }
    cout<<ans<<endl;
}
