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
int inp[MX];
int n,m;
string s;
int32_t main(){
    Init
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<m;i++){
        int l , r;
        char c,t;
        cin>>l>>r>>c>>t;
        for(int j=l-1;j<r;j++){
            if(s[j]==c){
                s[j]=t;
            }
        }
    }
    cout<<s<<endl;
}


