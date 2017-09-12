//be name khoda
//8)
//;)

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;

int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(k+2*m-1)/(2*m)<<" "<<(((k-1)%(2*m))/2)+1<< " "<< (k%2==0 ? "R":"L")<<endl;
}
