//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int inp[MX];
int n, x,k;
int low(int a){
    int l= -1,r= n;
    while(r-l>1){
        int m=(l+r)/2;
        if(inp[m]>=a){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}
int up(int a){
    int l= -1,r= n;
    while(r-l>1){
        int m=(l+r)/2;
        if(inp[m]>=a){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}
int32_t main(){
    Init
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    sort(inp,inp+n);
    int sum=0;
    for(int i=0;i<n;i++){
        int l=inf ,r=inf;
        if(!(inp[i]%x) && k){
            l= inp[i]+(k-1)*x;
            r= inp[i]+k*x;
        }else if((inp[i]%x) &&k){
            l= inp[i]-inp[i]%x+k*x;
            r= inp[i]-inp[i]%x+(k+1)*x;
        }else if(!k && inp[i]%x ){
            l =inp[i];
            r= inp[i]+(x-inp[i]%x);
        }
        int lower=low(l);
        //cout<<itlow<<endl;;
        int upper=up(r);
        sum+=upper-lower;
        //cout<<upper<<' '<<lower<<' ' <<r<<endl;
    }
    cout<<sum<<endl;
}


