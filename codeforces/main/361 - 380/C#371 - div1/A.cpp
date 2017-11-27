//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
struct Comp {
    bool operator() (const bitset<20> &b1, const bitset<20> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};
map<bitset<20>,int,Comp> mp;
int n;
bitset<20> convert(int a){
    bitset<20>ret;
    int cntr=0;
    while(a){
        if(a%2)
            ret[cntr]=1;
        a/=10;
        cntr++;
    }
    return ret;
}
int32_t main(){
    Init
    bitset<4> st;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='-'){
            int a;
            cin>>a;
            bitset<20> tmp;
            tmp= convert(a);
            mp[tmp]--;
        }else if(c=='+'){
            int a;
            cin>>a;
            bitset<20>tmp;
            tmp= convert(a);
            mp[{tmp}]++;
        }else{
            bitset<20>tmp;
            cin>>tmp;
            cout<<mp[tmp]<<endl;
        }
    }
}


