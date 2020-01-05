#include <bits/stdc++.h>
using namespace std;
#define int long long
const int KMX = 2e5 + 10;
int inp[KMX];
int plc[KMX];
int pre[KMX];
int sum(int l, int r){ /// []
    return pre[r] - pre[l-1];
}
int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(pre, pre + n + 10, 0);
        fill(plc, plc + n + 10, 0);
        fill(inp, inp + n + 10, 0);
        for (int i = 1; i <= n; i++) {
            cin >> inp[i];
            inp[i];
            pre[i] = pre[i-1] + inp[i];
            plc[inp[i]] = i;
        }
        int mn = 3e5;
        int mx = 0;
        for(int i = 1; i <= n; i++){
            mn = min(mn, plc[i]);
            mx = max(mx, plc[i]);
            if(abs(sum(mn, mx) ) == (1 + i)*i/2)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}
