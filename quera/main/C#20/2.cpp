#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 39;
const int inf=0x7FFFFFFF;


int n;
string s;

int main (){
    char c=49;
    cin>>s;
    if(s.size()==1&&(s[0]=='1'||s[0]=='2')){
        cout<<s;
    }else{
        int x=s.size();
        c=(int)s[x-1]-1;
        s[x-1]=c;
        for(int i=s.size()-1;i>0;i--){
            if((int)s[i]<48){
                s[i]='9';
                s[i-1]=(int)s[i-1]-1;
            }
        }
        while(s.size()>1 && s[0]=='0'){
            s.erase(0,1);
        }
        cout<<s<<endl;
    }
}
