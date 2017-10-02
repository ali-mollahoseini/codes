///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 07 |
///    | 25 |   CF Round 436   | 03 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 70000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
set<char>miz;
int32_t main(){
    Init
    int n;
    string s;
    cin>>n>>s;
    int mx=0;
    for(int i=0;i<n;i++){
        if(!isupper(s[i])){
            miz.insert(s[i]);
        }else{
            mx=max(1ll*miz.size(),mx);
            miz.clear();
        }
    }
    mx=max(miz.size()*1ll,mx);
    cout<<mx<<endl;;
}

