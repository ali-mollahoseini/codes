#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int mark[10];
        fill(mark,mark + 10,0);
        int n;
        cin >> n;
        pair<string,int> s[10];
        string ans[10];
        for(int i = 0; i < n; i++){
            cin >> s[i].first;
            s[i].second = i;
            mark[s[i].first[0]-'0'] = 1;
        }
        sort(s, s + n);
        int out = 0;
        for (int i = 0; i < n; i++ ){
            ans[s[i].second] = s[i].first;
            if(i && s[i].first == s[i - 1].first) {
                out++;
                int cnt = 0;
                while(cnt < 10){
                    if(!mark[cnt]){
                        ans[s[i].second][0] = '0' + cnt;
                        mark[cnt]=1;
                        break;
                    }
                    cnt++;
                }
            }
        }
        cout << out << endl;
        for(int i=0;i<n;i++){
            cout << ans[i] << endl;
        }
    }
}
