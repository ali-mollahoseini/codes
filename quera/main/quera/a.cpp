///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int main(){
    int a, b , c;
    cin>>a>>b>>c;
    if(a>0&& b>0 && c>0 ){
        if(a+b+c==180){
            cout<<"Yes";

        }else{
            cout<<"No";
        }
        return 0;
    }
    cout<<"No"<<endl;
}

