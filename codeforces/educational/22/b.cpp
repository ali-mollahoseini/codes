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
const int inf= 0x7FFFFFFFFFFFFFFF;
int a=1e18;
using namespace std;
vector<int> v;
int x,y,l,r;
int poww(int a,int p){
    if(p==0){
        return 1;
    }
    int ans;
    ans=pow(a,p/2);
    ans*=ans;
    if(p%2==1){
        ans*=a;
    }
    return ans;
}
int32_t main(){
    cin>>x>>y>>l>>r;
    bool tf=1;
    for(int i=0;i<100;i++){
        if(poww(y,i)>a||poww(y,i)<0){
            break;
        }
        for(int j=0;j<100;j++){
            if(poww(x,j)>a||poww(x,j)<0){
                break;
            }
            v.pb(poww(y,i)+poww(x,j));
        }
    }
    v.pb(inf);
    sort(v.begin(),v.end());
    int mx=0;
    for(int i=0;i<v.size();i++){
        //cout<<v[i]<<endl;
        if(v[i]<l&&v[i+(i!=v.size()-1)]<l){
            continue;
        }else if(v[i]>r){
            break;
        }else if(v[i]<l&&v[i+(i!=v.size()-1)]>=l){
            mx=max(mx,min(r,v[i+1])-max(l-1,v[i+1]));
            continue;
        }
        mx=max(mx,min(r+1,v[i+1])-v[i]-1);
    }
    cout<<mx<<endl;
}
