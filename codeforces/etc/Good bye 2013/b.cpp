//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int inp[MX1];
int32_t main(){
    string s;
    int n;
    cin>>n;
    for(int i=0,tmp;i<n-1;i++){
        cin>>tmp;
        while(tmp){
            s.pb('P');
            s.pb('R');
            s.pb('L');
            tmp--;
        }
        s.pb('R');
    }
    cin>>n;
    while(n){
        s.pb('P');
        s.pb('L');
        s.pb('R');
        n--;
    }
    cout<<s<<endl;
    return 0;

}
