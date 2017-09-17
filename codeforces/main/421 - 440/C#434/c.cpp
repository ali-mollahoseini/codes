///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 17 |   CF Round 434   | 26 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0),cin.tie(0);

const int MX = 2000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string s,ans;
bool iscons(char c){
    if(c!='e' && c!='a' && c!='o' && c!='i' &&c!='u' ){
        return 1;
    }
    return 0;
}
int32_t main(){
    Init
    cin>>s;
    int n =s.size();
    int cnt=0;
    bool yeki=1;
    for(int i=0;i<n;i++){
        if(!iscons(s[i])){
            ans.pb(s[i]);
            cnt=0;
            yeki=1;
        }else{
            if(cnt && s[i]!=s[i-1]){
                yeki=0;
            }
            if(cnt>=2&&!yeki){
                ans.pb(' ');
                ans.pb(s[i]);
                cnt =0;
                yeki =1;
            }else{
                ans.pb(s[i]);
            }
            cnt++;
        }
    }
    cout<<ans<<endl;
}

