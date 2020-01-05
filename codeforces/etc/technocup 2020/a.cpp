#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int KMX = 1e5 + 10;
pii in[KMX];
int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >>  n;
        for (int i = 0; i < n; i++){
            cin >> in[i].F >> in[i].S;
        }
        sort(in, in + n);
        int r  = in[n-1].F;
        sort(in, in + n, [](pii a, pii b){return a.S < b.S;});
        int l  = in[0].S;
        int ans =  max(r - l, 0LL);
        cout<<ans<<endl;
    }
}

