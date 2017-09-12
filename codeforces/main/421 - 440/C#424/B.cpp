#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
string s[2];
string con;
string ans;
char to(char a){
    bool tf=0;
    if(islower(a)){
        tf=1;
    }
    a=tolower(a);
    for(int i=0;i<26;i++){
        if(a==s[0][i]){
            a=s[1][i];
            break;
        }
    }
    if(tf==0){
        a=toupper(a);
    }
    return a;
}
int main(){
    cin>>s[0]>>s[1]>>con;
    for(int i=0;i<con.size();i++){
        if((int)con[i]<60){
            //cout<<i;
            ans.push_back(con[i]);
        }else{
            //cout<<i;
            ans.push_back(to(con[i]));
            //cout<<i;
        }
    }
    cout<<ans;
}
