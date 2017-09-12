/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=101;
const int MX2= 300*1000+10;
const int inf=2*1000*1000*1000+1000;
int n;
map<int,int> ich;
int def[MX2];
int a[MX2];
vector<int> g[MX2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int mx = -inf;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx, a[i]);
        ich[a[i]]++;
    }
    for(int i=0, u, v; i < n - 1; i++){
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    bool one = ich[mx] == 1 ;
    if(one){
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i] == mx){
                for(auto v : g[i]){
                    cnt += a[v] == mx-1;
                }
                if( cnt == ich[mx-1]){
                    cout << mx << endl;
                }else{
                    cout<<mx+1 << endl;;
                }
            }
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(auto v : g[i]){
            cnt += a[v] == mx;
        }
        if(cnt + (a[i] == mx) == ich[mx] ){
            cout << mx + 1 << endl;
            return 0;
        }
    }
    cout << mx + 2 << endl;
}
