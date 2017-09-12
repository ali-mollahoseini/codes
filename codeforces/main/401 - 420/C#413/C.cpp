#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define int long long
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000+1000;
vector<pair<int ,int> > v[2];
int solve(vector<pair<int,int> >vec, int x){
    sort(vec.begin(),vec.end());

    int n = vec.size();
    multiset<int> s;
    for(int i=0;i<n;i++){s.insert(vec[i].S);}
    int j=n-1;
    int ans = 0;
    for(int i=0;i<n;i++){
        while(j>-1&&vec[i].F + vec[j].F>x){
            s.erase(s.find(vec[j].S)),j--;
        }
        if(j==-1)break;
        if(j>=i)s.erase(s.find(vec[i].S));
        if(s.size()){
            ans = max(ans,vec[i].S+*s.rbegin());
        }
        if(j>=i)s.insert(vec[i].S);
    }
    return ans;
}
int32_t main(){
    int n, c, d;
    cin>>n>>c>>d;
    for(int i=0,b,p;i<n;i++){
        char tmp;
        cin>>b>>p>>tmp;
        v[tmp=='D'].push_back({p,b});//d =1 ,c=0;
    }
    int ans = 0 , mxc = -inf, mxd = -inf;
    for(auto u : v[0]){if(u.F<=c)  mxc=max(mxc,u.S);}
    for(auto u : v[1]){if(u.F<=d)  mxd=max(mxd,u.S);}
    ans = max(ans,mxc + mxd);
    ans = max(ans, solve(v[0], c));
    ans = max(ans, solve(v[1], d));
    cout<<ans;
}
