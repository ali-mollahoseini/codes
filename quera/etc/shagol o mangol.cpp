///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=1000;
const int inf= 0x7FFFFFFF;
using namespace std;
string s;
string infixToPostfix(string fst);
int32_t main(){
    cin>>s;
    cout<<infixToPostfix(s)<<endl;
}
int p(char x){
    if(x=='('){
        return 1;
    }else if(x == '+' || x == '-'){
        return 2;
    }else if(x == '*' || x == '/'){
        return 3;
    }
}
string infixToPostfix(string fst){
    vector<char> stk;
    string ans;
    for(int i=0;i<fst.size();i++){
        //cout<<i<<endl;
        if((int)fst[i]-'A'<30 &&(int)fst[i]-'A'>=0){
            ans.pb(fst[i]);
        }else if(fst[i]=='('){
            stk.pb(fst[i]);
        }else if(fst[i]== ')'){
            char tmp =stk.back();
            stk.pop_back();
            while(stk.size()&& tmp != '('){
                ans.pb(tmp);
                //cout<<1<<endl;
                tmp = stk.back();
                stk.pop_back();
            }
        }else{
            while(stk.size() && p(fst[i]) <= p(stk.back())){
                ans.pb(stk.back());
                stk.pop_back();
            }
            stk.pb(fst[i]);
        }
    }
    while(stk.size()){
        ans.pb(stk.back());
        stk.pop_back();
    }
    return ans;
}
