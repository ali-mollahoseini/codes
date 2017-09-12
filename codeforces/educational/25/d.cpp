//in the name of Allah
#include <iostream>
#define ll long long
const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;
string s,t;

int first[30],second[30];
int main(){
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]!='?'){
            first[s[i]-'a']++;
        }
    }
    for(int i=0;i<t.size();i++){
        second[t[i]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='?'){
            int pl=0;
            double mn=1e9;
            for(int j=0;j<28;j++){
                if(second[j]!=0){
                    if((double)((double)first[j]/(double)second[j])<mn){
                        mn=(double)((double)first[j]/(double)second[j]);
                        //cout<<mn<<endl;
                        pl=j;
                    }
                }
            }
            first[pl]++;
            s[i]='a'+pl;
        }
    }
    cout<<s;
}
