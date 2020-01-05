#include <bits/stdc++.h>
using namespace std;
#define int  long long
int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        int r, b, k;
        cin >> r >> b >> k;
        int gcd = __gcd(r, b);
        if(r > b)
            swap(r, b);
        r /= gcd;
        b /= gcd;
        if ((k - 1)*r + 1 < b)
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
}
