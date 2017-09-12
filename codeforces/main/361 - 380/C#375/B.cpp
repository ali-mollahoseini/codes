#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    bool opn=0;
    int wrds=0,mx=0,cntr=0;
    for(int i=0;i<n;i++){
        if(s[i]==')'||s[i]=='('||s[i]=='_'){
            if(cntr&& opn){wrds++;}
            if(cntr&&!opn){mx=max(mx,cntr);}
            if(s[i]!='_' ){opn= (!opn);}
            cntr=0;
        }else{
            cntr++;
        }
    }
    mx=max(mx,cntr);
    cout<<mx<<" "<<wrds<<endl;
}
