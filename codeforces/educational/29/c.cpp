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
void is_palindrome(string str){
    string tmp;
    reverse_copy(str.begin(),str.end(),tmp.begin());
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
        s.push_front(0);
    }
    cout<<"NO"<<endl;
}
