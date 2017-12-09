//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n, k;
string s;
map<char,int>mark;
int32_t main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        mark[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mark[s[i]]==1){
            cout<<s[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}


