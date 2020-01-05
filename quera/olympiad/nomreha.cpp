#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MX = 1e6 + 10;
pair<int, int> inp[MX];
int32_t main(){
    int n, m;
    cin >> n >> m;
    m/=n;
    m-=(n-1)/2;
    for(int i=0;i<n;i++){
        cin >> inp[i].first;
        inp[i].second = i;
    }
    sort(inp, inp + n);
    for(int i=0;i<n;i++){
        inp[i].first = m;
        m++;
        swap(inp[i].first, inp[i].second);
    }
    sort(inp, inp + n);
    for(int i=0;i<n;i++){
        cout <<  inp[i].second << " \n"[i == n-1];
    }
}
