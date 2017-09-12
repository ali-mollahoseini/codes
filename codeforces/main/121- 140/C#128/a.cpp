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
int32_t main(){
    int x, t, a, b, da, db;
    cin>>x >>  t >> a>> b >> da >> db;
    for(int i=0;i<t;i++){
        int tmp= a-da*i;
        for(int j=0;j<t;j++){
            int tmp1= b - db * j;
            if(x == tmp + tmp1||x==0|| x== tmp|| x==tmp1){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
