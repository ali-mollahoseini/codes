//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;

int32_t main(){
    int n, k;
    cin>>n >> k ;;
    k=240-k;
    int t=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=(i+1)*5;
        if(k<sum){
            break;
        }
        t=i+1;
    }
    cout<<t;
}

