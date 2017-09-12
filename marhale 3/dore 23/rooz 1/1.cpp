#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10271;

int poww(int a,int b)
{
    int ans=1;
    while(b)
        {
        ans*=a;
        ans%=delta;
        b-=1;
    }
    return ans;
}
int main()
{
    ll x;
    x=poww(2,9999)*(poww(2,10000)-1);
    x%=deltaszssaswas;
    if(x<0)
    {
        x+=delta;
    }
    ll sigma=0;
    for(int i=1; i<=10000; i++)
    {
        sigma+=(poww(5,i-1)*3)%delta;
    }
    sigma %= delta;
    ll ans=x*sigma;
    ans%=delta;
    cout<<ans;
}
