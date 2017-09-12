//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int sum[MX1];
int32_t main(){
    int a, b , c;
    cin>>a>>b>>c;
    int sum= a%2+ b%2+c%2;
    if(sum==2){
        if(a%2==0){
            cout<<"YES"<<" "<<"NO"<<" "<<"NO"<<endl;
        }else if(b%2==0){
            cout<<"NO"<<" "<<"YES"<<" "<<"NO"<<endl;
        }else if(c%2==0){
            cout<<"NO"<<" "<<"NO"<<" "<<"YES"<<endl;
        }
    }else if(sum==1){
        if(a%2==1){
            cout<<"YES"<<" "<<"NO"<<" "<<"NO"<<endl;
        }else if(b%2==1){
            cout<<"NO"<<" "<<"YES"<<" "<<"NO"<<endl;
        }else if(c%2==1){
            cout<<"NO"<<" "<<"NO"<<" "<<"YES"<<endl;
        }
    }else{
        cout<<"NO"<<" "<<"NO"<<" "<<"NO"<<endl;
    }
        return 0;
}

