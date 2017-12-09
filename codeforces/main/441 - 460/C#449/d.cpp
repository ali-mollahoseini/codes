//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 1e18+2,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int dp[MX],n,k,q;
string  a = "What are you doing at the end of the world? Are you busy? Will you save us?",
        b = "What are you doing while sending \"",
        c = "\"? Are you busy? Will you send \"", d = "\"?";
int32_t main(){
    Init
    cin>>q;
    dp[0]=a.size();
    int cntr=0;
    while(dp[cntr]<inf){
        cntr++;
        dp[cntr]=dp[cntr-1]*2+b.size()+c.size()+d.size();
    }
    cin>>n>>k;
    while(n>cntr){
        n--;
        k-=b.size();
    }
    while(k>dp[cntr]){
        cntr--;
    }
    if(n>=cntr){

    }else{
        cout<<'.';
    }
}

