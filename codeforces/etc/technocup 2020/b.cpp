#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int KMX = 1e5;
bool mark[KMX];
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fill(mark, mark + n + 10, 0);
        vector<int> ans;
        bool tf = 1;
        int cnt = 1;
        for(int i = 1; i <= n; i++){
            int u;
            cin >> u;
            if(u < i){
                tf = 0;
            }
            if(!mark[u]){
                mark[u] = 1;
                ans.pb(u);
            }else{
                while(mark[cnt])
                    cnt++;
                ans.pb(cnt);
                mark[cnt] = 1;
            }
        }
        if(!tf){
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
    }
}

