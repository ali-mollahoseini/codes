#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

int avval[1389];

int main(){
    ll a=1389;
    ll cnt=0;
    for(int i=2;i<1390;i++){
        bool tf=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                tf=0;
                break;
            }
        }
        if(tf==1){
            avval[i-1]=1;
        }
    }
    bool tf=1;
    cnt=0;
    while(tf){
        tf=0;
        int tmp[1389];
        for(int i=0;i<1389;i++){
            tmp[i]=avval[i];
        }
        for(int i=0;i<1389;i++){
            if(i<1388){
                if(avval[i]==1 && avval[i+1]==0 ){
                    tmp[i]=0;
                    tmp[i+1]=1;
                    tf=1;
                }
            }
        }
        for(int i=0;i<1389;i++){
            avval[i]=tmp[i];
        }
        cnt++;
    }
    cnt--;
    cout<<cnt<<" "<<cnt*cnt<<" "<<(ll)cnt*cnt*cnt<<endl;
    ll x=cnt+cnt*cnt+cnt*cnt*cnt;
    x%=10979;
    cout<<x;
}
