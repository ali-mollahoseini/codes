//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2*1000*1000 + 20000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int inp[MX],n;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        inp[x+1] = x;
    }
    for(int i=1;i<MX; i++)
        inp[i]= max(inp[i],inp[i-1]);
    int mx=0;
    for(int i=2;i<MX;i++){
            //cout<<1<<endl;
        if(inp[i]==i-1){
            int md =0;
            for(int j=i-1;j<MX;j+=i-1){
                if(inp[j]>=i-1){
                    md =max(md,inp[j]%(i-1));
                }
            }
            mx = max(mx, md);
        }
    }
    cout<<mx<<endl;
}


