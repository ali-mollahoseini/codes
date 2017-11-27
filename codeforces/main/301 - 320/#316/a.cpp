//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100 + 10,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n, m;
int inp[MX];
int32_t main(){
    Init
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int arr[MX],mx =0 , ind;
        for(int j = 0;j<n;j++){
            cin>>arr[j];
            if(arr[j]>mx){
                mx =arr[j];
                ind = j;
            }
        }
        inp[ind]++;
    }
    int ind, mx = 0;
    for(int i=0;i<n;i++){
        if(inp[i]>mx){
            mx=inp[i];
            ind =i;
        }
    }
    cout<<ind+1<<endl;
}


