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
    int cnt1=0,cnt2=0;
    int ans=0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]==')'){
            if(cnt1){
                cnt1--;
            }else{
                cnt2++;
            }
        }else{
            cnt1++;
        }
    }
    ans+=(cnt1 / 2) + (cnt2 / 2) + (cnt1 % 2) + (cnt2 % 2);
    cout << ans << endl;
}
