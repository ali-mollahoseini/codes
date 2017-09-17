///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
map<char,int> mp;
int32_t main(){
    string s;
    int n;
    cin>>n>>s;
    n--;
    int cntr=0;
    for(int i=0;i<n;i++){
        int key=i*2,dor= 2*i+1;
        char c=tolower(s[dor]);
        mp[s[key]]++;
        if(mp[c]>0){
            mp[c]--;
        }else{
            cntr++;
        }
    }
    cout<<cntr;
    return 0;
}

