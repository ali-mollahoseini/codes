#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=5*1000+100;
ll t,r,l;
ll dp[MX1][MX1];
ll cnt[MX1],ans[MX1];
string s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>s;
    int n =s.size();
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        cnt[1]++;
        if(s[i]==s[i+1]){
            dp[i][i+1]=2;
            cnt[2]++;
        }
    }
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i+1;j++){
            if(s[j]!=s[j+i]){
                dp[j][j+i]=0;
                continue;
            }else if(dp[j+1][j+i-1]==0){
                dp[j][j+i]=0;
                continue;
            }
            dp[j][j+i]=dp[j][(j+j+i+1)/2-1]+1;
            //cout<<j<<" "<<j+i<<" "<<dp[j][j+i]<< " " << dp[j][(j+j+i+1)/2-1] <<endl;;
            cnt[dp[j][j+i]]++;
        }
    }
    for(int i=0;i<n;i++){
        //cout<<cnt[i]<<endl;
        for(int j=i;j<n+1;j++){
            ans[i+1]+=cnt[j+1];
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i+1]<<" ";
    }
    cout<<endl;
}

