//in the name of Allah
#include <iostream>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX1 = 210;
using namespace std;
string s,t;

int32_t main(){
    int dp[MX1][10000];
    int n, k, p2[MX1], p5[MX1];
    cin>>n>> k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        while(a%2 == 0){
            a/=2;
            p2[i]++;
        }
        while(a%5 == 0){
            a/=5;
            p5[i]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<6000;j++){
            dp[i][j]=-inf;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j = k;j>0;j--){
            int tmp = p5[i];
            for(int q=tmp;q<6000;q++){
                dp[j][q]=max(dp[j][q],dp[j-1][q-tmp]+p2[i]);
            }
        }
    }
    int ans=0;
    for(int q=0;q<6000;q++){
        ans=max(min(q,dp[k][q]),ans);
    }
    cout<<ans;
}
