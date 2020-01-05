#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool ok = 1;
        if(s[0] == '?' && n > 1){
            s[0] = !(s[1] - 'a') + 'a';
        }else if(s[0] == '?') {
            s[0] = 'a';
        }
        for(int i = 1; i < n; i++){
            if (s[i] == '?'){
                for (int j = 0; j < 3; j++){
                    if(s[i-1] != 'a' + j && (i+1 >= n || s[i+1] != 'a' + j))
                        s[i] = 'a' + j;
                }
            }else if (s[i] == s[i-1]){
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        cout << s << endl;
    }
}
