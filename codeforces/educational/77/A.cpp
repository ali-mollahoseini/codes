#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0 ; i < n ; i++) {
        int k, sum;
        cin >> k >> sum;
        cout << (sum/k)*(sum/k)*(k-sum%k) + (sum/k+1)*(sum/k+1)*(sum%k)<<endl;
    }
}
