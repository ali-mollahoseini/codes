///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int inp[MX1][MX1];
int dp[MX1][MX1];
void solution(int l);
int32_t main(){
    int n;
    cin>>n;
    for(int i=0, l;i<n;i++){
        cin >> l;
        solution(l);
    }
    return 0;
}
void solution(int l){
    dp[0][0]=0;
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j =0;j <= i;j++){
            cin>>inp[i][j];
            int pt1 = dp[max(i - 1, 0LL)][max(j - 1, 0LL)], pt2 = dp[max(i - 1, 0LL)][j];
            dp[i][j]=max(pt1, pt2)+ inp[i][j];
            if(i==l-1){
                ans= max(ans, dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}
