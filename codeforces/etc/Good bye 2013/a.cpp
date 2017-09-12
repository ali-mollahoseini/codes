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
    int a,b;
    cin>>a>>b;
    int cur=a,nu=0;
    int sum=0;
    while(cur){
        sum+=cur;
        int tmp=(cur+nu)-((cur+nu)/b)*b;
        cur= (cur+nu)/b;
        nu=tmp;
    }
    cout<<sum<<endl;
}

