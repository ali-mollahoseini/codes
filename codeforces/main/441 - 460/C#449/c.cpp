//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int avval[5]={1,2,3,5,7};
int n, m, c;
vector<int> ans;
int bin(int val){
    int l = -1, r= ans.size();
    while(abs(r-l)>1){
        int mid = (r+l)/2;
        if(ans[mid]>val){
            r= mid;
        }else{
            l=mid;
        }
    }
    //cout<<r<<endl;
    return r;
}
int32_t main(){
    Init
    cin>>n>>m>>c;
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        int x =bin(val);
        if(x==ans.size() && ans.size()<n){
            ans.pb(val);
            cout<<ans.size()<<endl;
            cout<<flush;
        }else{
            if(x==n){
                ans[n-1]=val;
                cout<<x<<endl;
            }else{
                ans[x]=val;
                cout<<x+1<<endl;
            }
            cout<<flush;
        }
    }
}


