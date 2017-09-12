#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000*100+100;
const int MX2= 1000*1000+100;
const int inf=2*1000*1000*100;
int n;
string hm;
int main(){
    cin>>n;
    cin>>hm;
    int raft=0,bar=0;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        if(tmp.substr(5,7)==hm){
            bar++;
        }else{
            raft++;
        }
    }
    if(raft==bar){
        cout<<"home"<<endl;
    }else{
        cout<<"contest"<<endl;
    }
}
