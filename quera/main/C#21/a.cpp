///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
string s1, s2;
bool despc(){
    int cntr=0;
    while(cntr<s1.size()){
        if(s1[cntr]==' '){
            s1.erase(s1.begin()+cntr);
        }else {
            cntr++;
        }
    }
    cntr=0;
    while(cntr<s2.size()){
        if(s2[cntr]==' '){
            s2.erase(s2.begin()+cntr);
        }else {
            cntr++;
        }
    }
     //cout<<1<<endl;
    if(s1==s2){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    string tmp;
    getline(cin,tmp);
    int ans=0;
    for(int i=0;i<n;i++){
        getline (cin,s1);
        getline (cin,s2);
        //cout<<s1<<" "<<s2<<endl;
        if(!despc()){
            ans++;
        }
        s1.clear();
        s2.clear();
    }
    cout<<ans;
    return 0;
}

