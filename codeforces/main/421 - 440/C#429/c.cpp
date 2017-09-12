//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;
const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
vector<pair<int,int> >b ;
vector<int>a;
int  aprim[MX1];
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0, tmp;i<n;i++){
        cin>>tmp;
        a.pb(tmp);
    }
    sort(a.rbegin(), a.rend());
    for(int i=0, tmp;i<n;i++){
        cin>>tmp;
        b.pb({tmp, i});
    }
    sort(b.begin(), b.end());
    for(int i=0;i<n;i++){
        pair<int,int> pt = b[i];
        aprim[pt.S] = a[i];
    }
    for(int i=0;i<n;i++){
        cout<<aprim[i]<<" ";
    }
    cout<<endl;
    return 0;
}
