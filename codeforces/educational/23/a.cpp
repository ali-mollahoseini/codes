//be name khoda
//8)
//;)
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
    int x1,x2, y1 ,y2,x,y;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    if(((x1%x)+x)%x == ((x2%x)+x)%x && ((y1%y)+y)%y == ((y2%y)+y)%y){
        if((abs(x2-x1)/x)%2 == (abs(y2-y1)/y)%2){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

