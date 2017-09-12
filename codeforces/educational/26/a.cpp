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
int vol(string s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'a'<0){
            ans++;
        }
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    int mx=0;
    string tmp;
    bool tf=1;
    int sum=0;
    while(tf){
        cin>>tmp;
        sum+=tmp.size()+1;
        if(sum>=n){
            tf=0;
        }
        mx=max(vol(tmp),mx);
    }
    cout<<mx;
}

