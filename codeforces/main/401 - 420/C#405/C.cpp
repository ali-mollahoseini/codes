#include <bits/stdc++.h>

#define ll long long

const int inf=0x7FFFFFFF;
const int MX1=200*1000+1000;
using namespace std;
int n,k;
string make(int x){
    string ans;
    if(x>=26){
        ans.push_back('A'+x/26-1);
        ans.push_back('a'+x%26);
    }else{
        ans.push_back('A'+x%26);
    }
    return ans;
}
string s[200];
int main(){
    cin>>n>>k;
    int cntr=0;
    for(int i=0;i<n;i++){
        s[i]=make(cntr);
        cntr++;
    }
    int w=n-k+1;
    for(int i=0;i<w;i++){
        string tmp;
        cin>>tmp;
        if(tmp=="NO"){
            s[i+k-1]=s[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
