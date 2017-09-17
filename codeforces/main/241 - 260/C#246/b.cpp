//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
map<int,int> mp;
pair<int,int> col[MX1];
pair<int,int> ans[MX1];
int32_t main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>col[i].F>>col[i].S;
        mp[col[i].F]++;
    }
    for(int i =0;i<n;i++){
        ans[i].F=n-1;
        ans[i].S=n-1;
    }
    for(int i =0;i<n;i++){
        int dif=mp[col[i].S];
        ans[i].S-=dif;
        ans[i].F+=dif;
    }
    for(int i =0;i<n;i++){
        cout<<ans[i].F<<" "<<ans[i].S<<endl;
    }
}
