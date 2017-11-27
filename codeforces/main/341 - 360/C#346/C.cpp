
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define Init ios::sync_with_stdio(0);

using namespace std;

const int mod=1000*1000*1000+7;
const int MX=2*1000*100+100;
const int inf=0x7FFFFFFF;
int n , m;
bool mark[MX];
vector<int> ans;
int main(){
    Init
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val<MX){
            mark[val]=1;
        }
    }
    int cur=1;
    while(cur<=m){
        if(mark[cur]!=1){
            ans.pb(cur);
            m-=cur;
        }
        cur++;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<1ll*ans.size();i++){
        cout<<ans[i]<<' ';
    }
}
