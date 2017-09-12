//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;

int32_t main(){
    int n;
    pair<int,int> pap;
    cin>>n>>pap.F>> pap.S;
    if(pap.S>pap.F){
        swap(pap.S,pap.F);
    }
    vector< pair<int,int> > v;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        pair<int,int> tmp={max(a,b),min(a,b)};
        if(tmp.F<=pap.F&& tmp.S<=pap.S) {
            v.pb(tmp);
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(j==i){continue;}
            bool tf=0;
            //cout<<1<<endl;
            int tmp=v[i].F*v[i].S+v[j].F*v[j].S;
            if(v[i].F+v[j].F<=pap.F ){tf=1;}
            if(v[i].F+v[j].S<=pap.F && v[j].F<=pap.S){tf=1;}
            if(v[i].S+v[j].F<=pap.F && v[i].F<=pap.S){tf=1;}
            if(v[i].S+v[j].S<=pap.F && v[i].F<=pap.S && v[j].F<=pap.S){tf=1;}
            if(v[i].F+v[j].F<=pap.S ){tf=1;}
            if(v[i].F+v[j].S<=pap.S ){tf=1;}
            if(v[i].S+v[j].F<=pap.S ){tf=1;}
            if(v[i].S+v[j].S<=pap.S ){tf=1;}
            if(tf)  ans=max(tmp,ans);
        }
    }
    cout<<ans;
}
