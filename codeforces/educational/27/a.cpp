//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=500+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int n , inp [MX1];
int32_t main(){
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>inp[i];
    }
    sort(inp, inp+ 2*n);
    if(inp[n]>inp[n-1]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}


