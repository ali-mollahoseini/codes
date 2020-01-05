#include <bits/stdc++.h>
using namespace std;
#define int long long
const int KMX = 4e5 + 10;
int in[KMX];
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int g = 0, s = 0, b = 0;
        for (int i = 0; i < n; i++){
            cin >> in[i];
            if(!g && i && in[i] != in[i-1])
                g = i;
            else if(g && !s && i - g > g && in[i] != in[i-1])
                s = i;
            else if(s && i <= n/2 && i - s > g && in[i] != in[i-1])
                b = i;
        }
        if(g && s && b){
            cout << g << ' ' << s - g << ' ' << b - s << endl;
        }else{
            cout << 0 << ' ' << 0 << ' ' << 0 << endl;
        }
    }
}
