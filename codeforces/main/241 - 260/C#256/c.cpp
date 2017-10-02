//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX=1000*100+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int dp[MX];
int n;
int ar[MX];
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int cntr=0;
    for(int i = 0 ;i<n;i++){
        while(ar[i+1] && ar[i]){
            cntr++;
            for(int j=i;j<n&&ar[j];j++){
                ar[j]--;
            }
        }
        if(ar[i]){
            cntr++;
        }
    }
    cout<<cntr;
}
