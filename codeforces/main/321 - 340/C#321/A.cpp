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
int32_t main(){
    Init
    int n;
    cin>>n;
    int lst =0,mx=0,cntr=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<lst){
            mx = max(mx , cntr);
            cntr=1;
            lst =a;
        }else{
            cntr++;
            lst = a;
            mx =max(cntr,mx);
        }
    }
    cout<<mx<<endl;
}


