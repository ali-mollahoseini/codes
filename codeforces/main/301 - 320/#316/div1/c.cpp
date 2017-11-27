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
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000 * 1000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string ans;
pair<int,int> out[MX];
int n,k;
int sum;
set<int> st;
pair<int,int> ar[MX];
int ord[MX];
void cost(){
    for(int i=k;i<k+n;i++){
        sum+=out[i].F*abs(i-out[i].S);
    }
}
int32_t main(){
    Init
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0,u;i<n;i++){
        st.insert(k+i);
        cin>>u;
        ar[i]={u,i};
    }
    sort(ar,ar+n,greater<pair<int,int> >());
    for(int i=0;i<n;i++){
        auto x = st.upper_bound(ar[i].S-1);
        ord[ar[i].S]=*x;
        out[*x] = {ar[i].F ,ar[i].S} ;
        st.erase(x);
    }
    cost();
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<ord[i]+1<<" ";
    }
    cout<<endl;
}

