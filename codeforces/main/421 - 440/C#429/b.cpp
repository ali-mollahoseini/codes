//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;
const int MX1=1000*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int ar[MX1];
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //string ans;
    int n;
    cin>> n;
    int sum=0;
    bool odd=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        sum+=ar[i];
        if(ar[i]%2){
            odd =  1;
        }
    }
    if((odd && sum%2==0) || (sum%2) ){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}
