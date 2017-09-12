//be name khoda
//8)
//;)
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;

map<int,int> mp;
vector<int> ar;
int32_t main(){
    int n=0;
    cin>>n;
    int mx1=inf,mx2=inf,mx3=inf;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        ar.pb(tmp);
        mp[ar[i]]++;
    }
    sort(ar.rbegin(),ar.rend());
    for(int i=0;i<n;i++){
        if(ar[i]<=mx1){
            mx3=mx2;
            mx2=mx1;
            mx1=ar[i];
        }
    }
    ll ans=1;
    //cout<<mx3<< " "<<mx2<<" "<<mx1<< endl;
    if(mx1==mx3){
        ans*=mp[mx1];
        mp[mx1]--;
        ans*=mp[mx2];
        mp[mx2]--;
        ans*=mp[mx3];
        ans/=6;
    }else if(mx3==mx2){
        //cout<<1<<endl;
        ans*=mp[mx1];
        mp[mx1]--;
        ans*=mp[mx2];
        mp[mx2]--;
        ans*=mp[mx3];
        ans/=2;
    }else if(mx2==mx1){
        ans*=mp[mx1];
        mp[mx1]--;
        ans*=mp[mx2];
        mp[mx2]--;
        ans*=mp[mx3];
        ans/=2;
    }else{
        ans*=mp[mx1];
        mp[mx1]--;
        ans*=mp[mx2];
        mp[mx2]--;
        ans*=mp[mx3];
    }
    cout<<ans<<endl;;
}
