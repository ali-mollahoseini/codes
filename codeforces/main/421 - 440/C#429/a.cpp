///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;
const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int siz[100];
int32_t main(){
    int n , k;
    cin>> n >> k;
    string tmp;
    cin>>tmp;
    for(int i=0;i<n;i++){
        siz[(int)tmp[i]-'a']++;
    }
    string ans="YES";
    for(int i=0;i<26;i++){
        if(siz[i]>k){
            ans="NO";
        }
    }
    cout<<ans<<endl;
}
