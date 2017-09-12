/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=101;
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000+1000;
string s1, s2 ;
string ans1, ans2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2 ;
    int n = s1.size();
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end(),greater<char>());
    s1.erase(s1.begin()+(n+1)/2,s1.end());
    s2.erase(s2.begin()+n/2,s2.end());
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            if(s1[0] < s2[0]){
                ans1.push_back(s1[0]);
                s1.erase(s1.begin());
            }else{
                ans2.push_back(s1.back());
                s1.erase(s1.end()-1);
            }
        }else{
            if(s2[0] > s1[0]){
                //cout << 1 << " ";
                //cout << 2 << endl;
                ans1.push_back(s2[0]);
                s2.erase(s2.begin());
            }else{
                ans2.push_back(s2.back());
                s2.erase(s2.end()-1);
            }
        }
    }
    reverse(ans2.begin(),ans2.end());
    cout << ans1 << ans2 ;
}
