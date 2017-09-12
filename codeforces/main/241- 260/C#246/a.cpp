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
    int n,k;
    cin>>n>>k;
    int kp=5-k;
    int sum=0;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        sum += (tmp<=kp);
    }
    cout<<sum/3;
}

