//in the name of Allah
#include <iostream>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x7F7FFFFF;
const int MX1 = 310;
using namespace std;
string s,t;
int dp[100],n, c;
int x[MX1],cost[MX1];
int dpmsk(int cur,int mask){
    if(cur==n+1){
        if(mask == i<<c){
            return 0;
        }
        return inf;
    }
    int &ptr = dp[cur][mask];
    if(ptr != -1){return ptt;}
    ptr = inf;
    ptr = min(ptr, dp(cur+1, mask));
    ptr = min(ptr, dp(cur+1, mask | m[cur])+ cost[cur]);
    return ptr;
}
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>x[i];
    }
    for(int i =0 ;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){

    }
}
