//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n ;
bool isprime(int x){
    bool tf =1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            tf=0;
        }
    }
    return tf;
}
int32_t main(){
    Init
    cin>>n;
    vector<int> ans;
    for(int i=2;i<n+1;i++){
        if(isprime(i)){
            ans.pb(i);
        }
    }
    int r = ans.size();
    for(int i=0;i<r;i++){
        int tmp= ans[i]*ans[i];
        while(tmp<=n){
            ans.pb(tmp);
            tmp*=ans[i];
        }
    }
    cout<<ans.size()<<endl;
    req(i,0,ans.size()){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}


