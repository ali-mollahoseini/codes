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
int n, k;
int inp[200];
int32_t main(){
    Init
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        bool tf=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                if(abs(inp[i]-inp[j])<=k){
                    tf=0;
                }
            }
        }
        sum+=tf;
    }
    cout<<sum<<endl;
}


