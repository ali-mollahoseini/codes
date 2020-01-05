#include <bits/stdc++.h>
#define int long long
using namespace std;
const int KMX =1e5 + 100, mod = 998244353;
int inp[KMX];
vector<int> wis[KMX];
int poww(int a, int p){
    if(a == 0)
        return 1;
    int ret = poww(a, p/2);
    if(p%2) return ret%mod*ret%mod*a%mod;
    return ret%mod*ret%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0, k; i < n; i++){
        cin >> k;
        for(int j = 0 ; j < k; j++){
            cout << k;
            int x;
            cin >> x;
            cout << x << endl;
            wis[x].push_back(k);
        }
    }
    int ans = 0;
    for(int i = 0; i < KMX;i ++){
            cout << "fuck\n";
        int tmp = 0;
        for(int j = 0; j < wis[i].size(); j ++){
            tmp = (tmp + wis[i][j]%mod*poww(n, mod-2)%mod)%mod;
        }
        if(wis[i].size())
            ans = (ans+tmp%mod*wis[i].size()%mod*poww(n, mod-2)%mod)%mod;
    }
    return 0;
}
