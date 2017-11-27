//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 1000,inf = 0x7FFFFFFF;
using namespace std;
int mod =1000 * 1000 * 1000 + 7;
int power(int x, int y) {
    if(y == 0) return 1;

    int d = power(x, y>>1);
    int ans=1;
    if((y&1) == 0) ans = (d*d)%mod;
    else ans = (x*d*d)%mod;
    while(ans<0){ans+=mod;}
    return ans;
}
int32_t main(){
    Init
    int n,m,k;
    cin>>n>>m>>k;
    if(k==-1){
        if(m%2==0||n%2==0&&n%2!=m%2){
            cout<<0<<endl;
            return 0;
        }
    }
    if(n==1||m==1){
        if(k==1 && max(n,m)%2==0){
            cout<<0<<endl;
            return 0;
        }
        cout<<1<<endl;
        return 0;
    }
    int val= power(2,n-1);
    int val2 = power(2,m-1);
    int t =(val*val2)%mod;;
    cout<<t<<endl;
}


