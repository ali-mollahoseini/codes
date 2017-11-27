//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int inp[MX],n;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    bool tf=1;
    for(int i=0;i<n;i++){
        if(inp[i]!=1){
            tf=0;
        }
    }
    if(tf){
        cout<<0<<endl;
        return 0;
    }
    int mn =inf;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(__gcd(inp[i],inp[j])==1){
                tf=1;
                mn =min(mn, j-i-1);
            }
        }
    }
    if(tf){
        cout<<mn+n<<endl;
    }else{
        cout<<-1<<endl;
    }
}


