//in the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
ll n,m;
string t,s;


int num(string a, string b,int r){
    int ans=0;
    for(int  i=0;i<n;i++){
        if(a[i] != b[i+r]){
            ans++;
        }
    }
    return ans;
}

int main(){
    cin>>n>>m;
    cin>>s>>t;
    int shom=-1;
    int mn=inf;
    for(int i=0;i+n-1<m;i++){
        if(num(s,t,i)<mn){
            shom=i;
            mn=num(s,t,i);
        }
    }
    cout<<mn<<endl;
    for(int i=0;i<n;i++){
        if(s[i] != t[i+shom]){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}
