//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,inp[MX];
string s;
int32_t main(){
    Init
    cin>>s;
    int n = s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='Q'){
            for(int j =i+1;j<n;j++){
                if(s[j]=='A'){
                    for(int k =j+1;k<n;k++){
                        if(s[k]=='Q'){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
}


