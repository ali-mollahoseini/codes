#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MX = 1e6 + 100;
int loop[MX], inp[MX], mark[MX];
int32_t main(){
    int k, n;
    cin >> k >> n;
    fill(mark, mark + k + 10, -1);
    for (int i = 0; i < k ; i++) {
        cin >> inp[i];
        if(inp[i] <= k + 1) {
            mark[inp[i]] = i;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= k + 1; i++) {
        loop [max (cnt, mark[i]+1) ] = i;
        while (loop[cnt]) {
            cnt++;
        }
    }
    cout << loop[(n - k - 1)%(k + 1)] << endl;
}
