///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 2000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int  n;
vector<double> inp;
bool check(double x){
    set<double> st;
    for(int i=0;i<n;i++){
        st.insert(inp[i]-x*(i+1));
    }
    return st.size()==2;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0,u;i<n;i++){
        cin>>u;
        inp.pb(u);
    }
    if(check(inp[1]-inp[0]) || check((inp[2]-inp[0])/2) ||check(inp[2]-inp[1])) cout<<"yes"<<endl;
    else cout<<"NO"<<endl;
}
