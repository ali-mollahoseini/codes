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
int n;
vector<pair<int,int> > inp ;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.F!=b.F){
        return a.F<b.F;
    }
    return a.S<b.S;
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0,u, v;i<n;i++){
        cin>>u >> v;
        inp.pb({u,1});
        inp.pb({v,2});
    }
    sort(inp.begin(),inp.end(),comp);
    int cntr=0;
    for(int i=0;i<inp.size();i++){
        //cout<<inp[i].F<<inp[i].S<<endl;
        if(inp[i].S==1){
            cntr++;
        }else{
            cntr--;
        }
        if(cntr>2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
