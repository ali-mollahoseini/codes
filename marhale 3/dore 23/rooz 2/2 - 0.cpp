#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int delta = 10181;
const int inf=0x7FFFFFFF;
//ifstream fin ("contact.in");
//ofstream fout ("contact.out");
ll poww (ll a,int b){
    int ans=1;
    while(b){
        ans*=a;;
        ans%=delta;
        b--;
    }
    return ans;
}
int main(){
    int ans=poww(5,1000);
    ans-=poww(4,1000);
    while(ans<0){
        ans+=delta;
    }
    ans-=poww(4,1000);
    while(ans<0){
        ans+=delta;
    }
    ans+=poww(3,1000);
    ans%=delta;
    cout<<ans;
}
