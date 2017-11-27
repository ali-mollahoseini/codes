//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
map<int,int> mp;
int mx[MX];
int32_t main(){
    Init
    int n;
    cin>>n;
    req(i,0,n){
        int a;
        cin>>a;
        mx[a]++;
    }
    int ans=0;
    for(int i=0;i<1000*1000+30;i++){
        if(mx[i]%2){
            ans++;
            mx[i]--;
        }
        mx[i+1]+=mx[i]/2;
    }
    cout<<ans<<endl;
}


