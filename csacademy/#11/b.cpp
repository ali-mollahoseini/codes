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
pair<int,int> inp[MX];
int n ;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i].F>>inp[i].S;
    }
    sort(inp,inp+n);
    int lst, sum=0;
    int x =n/2;
    lst = inp[x].S;
    for(int j=x+1;j<n;j++){
        sum += inp[j].F-lst;
        lst += inp[j].S-inp[j].F;
    }
    lst = inp[x].F;
    for(int j=x-1;j>-1;j--){
        sum += lst-inp[j].S;
        lst -= inp[j].S-inp[j].F;
    }
    //cout<<sum<<' '<<i<<endl;
    sum;
    cout<<sum<<endl;
}


