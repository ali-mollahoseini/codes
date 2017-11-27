//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int inp[MX];
int32_t main(){
    Init
    int n ;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a;
        sum+=a;
    }
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    sort(inp,inp+n);
    if(sum<=inp[n-1]+inp[n-2]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}


