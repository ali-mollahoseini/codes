//in the name of god
// part a
#include <iostream>
#define ll long long
const int inf= 0x7FFFFFFF;

using namespace std;
ll j,k;
int32_t sol_a()
{
    ll a,b,c;
    cin>>j>>k;
    a=j/2;
    c=(j+1)/2;
    ll x=a%(k+1);
    a-=x;
    c+=x;
    a=(a/(k+1));
    b=a*k;
    cout<<a<<" "<<b<<" "<<c<<endl;

}
