#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> out;
        out.push_back(0);
        for (int i = 1; i*i <= n; i++){
            if(i == n/i){
                out.push_back(i);
                continue;
            }
            out.push_back(i);
            out.push_back(n/i);
        }
        sort(out.begin(), out.end());
        cout << out.size() << endl;
        for(int i = 0; i < out.size(); i++){
            cout << out[i] << " \n"[i == out.size()-1];
        }
    }
}
