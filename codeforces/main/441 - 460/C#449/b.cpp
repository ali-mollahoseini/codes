//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int sum;
int k,p;
int mok(int val){
    int tmp=val;
    int rtmp=0;
    vector<int> r;
    while(tmp){
        r.pb(tmp%10);
        tmp/=10;
    }
    for(int i=0;i<r.size();i++){
        val*=10;
        val+=r[i];
    }
    //cout<<val<<endl;
    return val;
}
int32_t main(){
    Init;
    cin>>k>>p;
    for(int i=1;i<k+1;i++){
        sum+=mok(i);
    }
    cout<<sum%p<<endl;
}


