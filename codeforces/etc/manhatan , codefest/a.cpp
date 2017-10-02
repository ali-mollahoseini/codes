///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 19 |   CF Round 434   | 28 |
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
int n ;
map<string, bool> mark;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        if(mark[tmp]){
            cout<<"YES"<<endl;
        }else{
            mark[tmp]=1;
            cout<<"NO"<<endl;
        }
    }
}

