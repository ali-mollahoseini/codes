#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int k[4],b[4]={0,1,2,3};
string s;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            b[0]=i%4;
        }else if(s[i]=='B'){
            b[1]=i%4;
        }else if(s[i]=='Y'){
            b[2]=i%4;
        }else if(s[i]=='G'){
            b[3]=i%4;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='!'){
            if(i%4==b[0]){
                k[0]++;
            }else if(i%4==b[1]){
                k[1]++;
            }else if(i%4==b[2]){
                k[2]++;
            }else if(i%4==b[3]){
                k[3]++;
            }
        }
    }
    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<" "<<k[3]<<endl;
}
