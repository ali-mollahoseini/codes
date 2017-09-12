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
    string s;
    int n;
    cin>>s>>n;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        sum[tmp]=(sum[tmp]+1)%2;
    }
    int ttl=0;
    for(int i=1;i<=s.size()/2;i++){
        ttl+=sum[i];
        if(ttl%2==1){
            swap(s[i-1], s[s.size()-i]);
        }
    }
    cout<<s<<endl;
    return 0;
}
