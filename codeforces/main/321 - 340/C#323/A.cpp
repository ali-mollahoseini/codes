//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 500*500 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
map<int,int> mp;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n*n;i++){
        int x ;
        cin>>x;
        mp[x]++;
    }
    vector<int> ans;
    for(map<int,int>::reverse_iterator it = mp.rbegin(); it!=mp.rend();){
        if(it->S==0){
            it++;
            continue;
        }
        mp[it->F]--;
        for(int i=0;i<ans.size();i++){
            mp[__gcd(it->F,ans[i])]--;
            mp[__gcd(it->F,ans[i])]--;
        }
        ans.pb(it->F);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

