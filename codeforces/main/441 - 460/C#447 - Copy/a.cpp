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
int inp[MX];
int n;
int32_t main(){
    Init
    cin>>n;
    int suma=0,sumb=0,sum;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        sum+=inp[i];
    }
    int mn = inf;
    for(int i=0;i<n;i++){
        suma=0;
        for(int j=i;j<n;j++){
            suma+=inp[j];
            mn = min(abs((360LL-suma)-suma),mn);
        }
    }
    cout<<mn<<endl;
}


