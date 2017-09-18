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
#define Init ios::sync_with_stdio(0);

const int MX = 70000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
map<string,int> miz;
int n;
string inp[MX];
void all(string s, bool check){
    //cout<<":::"<< s<<' '<<check<<endl;
    set<string> st;
    for(int i=1;i<10;i++){
        for(int j=0;j<9;j++){
            if(j+i>9){

                break;
            }
            if(!check && miz[s.substr(j,i)]==1){
                cout<<s.substr(j,i)<<endl;
                return;
            }
            if(check){
                st.insert(s.substr(j,i));
            }
            //cout<<s.substr(j,i)<<' '<<miz[s.substr(j,i)]<<endl;
        }
    }
    if(check){
        for(auto e: st){
            miz[e]++;
        }
    }
}
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        all(inp[i],1);
    }
    for(int i=0;i<n;i++){
        all(inp[i],0);
    }
}

