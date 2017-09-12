#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=8*1000*1000+100;
const int MX2= 2*1000+100;
const int inf=2*1000*1000*100;
int jury[MX2],rem[MX2],sum[MX2],k,n;
bool used[MX2];
set<int> st;
unordered_map<int,int> mp;
int main(){
    int ans=0;
    cin>>k>>n;
    int lst=0;
    for(int i=0;i<k;i++){
        cin>>jury[i];
        sum[i]=lst+jury[i];
        lst=sum[i];
    }
    for(int i=0;i<n;i++){
        cin>>rem[i];
        mp[rem[i]]=1;
    }
    for(int i=0;i<k;i++){
        st.insert(rem[0]-sum[i]);
    }
    for(auto e : st){
        //cerr<<1<<" ";
        int cntr=0;
        for(int i=0;i<k;i++){
            cntr+=mp[e+sum[i]];
            mp[e+sum[i]]=0;
        }
        for(int i=0;i<n;i++){
            mp[rem[i]]=1;
        }
        if(cntr==n){
            ans++;
        }
    }

    cout<<ans<<endl;
}
