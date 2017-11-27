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
map<int,int> mp;
int32_t main(){
    Init
    int n;
    cin>>n;
    int mn = inf,kil=0;
    int sum = 0;
    req(i,0,n){
        int a, b;
        cin>>a>>b;
        if(b<mn){
            sum+=kil*mn;
            kil=a;
            mn=b;
        }else{
            kil+=a;
        }
    }
    sum+=kil*mn;
    cout<<sum<<endl;
}


