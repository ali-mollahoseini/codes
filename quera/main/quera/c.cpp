//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int n, l;
int r[MX],g[MX],d1[MX],d[MX],s[MX];
int32_t main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>d[i]>>r[i]>>g[i];
        s[i]= r[i]+ g[i];
        if(i){
            d1[i]=d[i]-d[i-1];
        }
        else d1[0]=d[0];
    }
    int ans=0;
    int cur=0;
    for(int i=0;i<n;i++){
        cur+=d1[i];
        //cout<<cur%s[i]<<endl;
        if(cur%s[i]<r[i]){
            //cout<<ans<<' '<<i<<' '<<endl;
            ans+=r[i]-(cur%s[i]);
            //cout<<ans<<' '<<i<<'-'<<endl;
            cur+=r[i]-(cur%s[i]);
        }
    }
    ans+=l;
    cout<<ans<<endl;
    //cout<<cur<<endl;
}
