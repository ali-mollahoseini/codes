//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int inp[MX],n;
bool mark[MX];
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    int died=inf;
    int i= n-1;
    while(i+1){
        if(i>=died){
            mark[i]=1;
        }
        int x= inp[i];
        died= min(died,i-x);
        i--;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(!mark[i]){
            //cout<<i<<endl;
            sum++;
        }
    }
    cout<<sum<<endl;
}


