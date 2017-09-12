#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000;
string s;
int md(char a,char b){
    int tmp=abs((int)a-(int)b);
    int ans=min(26-tmp,tmp);
    return ans;
}
int main(){
    cin>>s;
    int sum=0;
    char lst='a';
    for(int i=0;i<s.size();i++){
        sum+=md(s[i],lst);
        lst=s[i];
    }
    cout<<sum;
}
