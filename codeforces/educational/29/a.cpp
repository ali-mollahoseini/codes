//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX1 = 502;
using namespace std;
string s;
bool is_palindrome(string str){
    string tmp;
    for(int i=str.size()-1;i>=0;i--){tmp.pb(str[i]);}
    //cout<<tmp<<endl;
    //cout<<tmp<<endl;
    if(tmp == str){
        return 1;
    }
    return 0;
}
int32_t main(){
    cin>>s;
    for(int i=0;i<10;i++){
        if(is_palindrome(s)){
            cout<<"YES";
            return 0;
        }
        s.insert(0,"0");
    }
    cout<<"NO"<<endl;
}
