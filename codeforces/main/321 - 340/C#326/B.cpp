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
int32_t main(){
    Init
    int n ;
    cin>>n;
    int ans=1;
    int tmp = n;
    for(int i=2;i*i<=n;i++){
        if(tmp%i==0){
            ans*=i;
            while(tmp%i==0){
                tmp/=i;
            }
        }
    }
    ans*=tmp;
    cout<<ans<<endl;
}


