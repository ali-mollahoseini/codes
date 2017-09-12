///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1 = 100 * 1000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
set<int > st;
vector<int> anss;
int n;
int32_t main(){
    cin >> n;
    int lst=-1;
    for(int i=0, u;i<n;i++){
        cin>>u;
        int ans=0;
        if(lst == u){
            anss.pb(0);
            continue;
        }
        set<int>::iterator iend = st.lower_bound(u);
        ans = distance(st.begin(), iend);
        st.erase(st.begin(), iend);
        anss.pb(ans);
        st.insert(u);
        lst = u;
    }
    for(int i=0;i<anss.size();i++){
        cout<<anss[i]<<" ";
    }
    cout <<  endl;
}

