#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;

int ar[42000];
int maghsoms(int a){
    map<int,int> tmp;
    for(int i=0;i<=41670;i++){
        while(a%ar[i]==0){
            tmp[ar[i]]++;
            a/=ar[i];
        }
        if(a==1){
            break;
        }
    }
    int ans=1;
    for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++){
        ans*=(it->second+1);
    }
    return ans;
}
int main(){
    int cntr=0;
    for(int i=2;i<MX1/2+100;i++){
        bool tf=1;
        for(int j=2;j*j<i;j++){
            if(i%j==0){
                tf=0;
                break;
            }
        }
        if(tf==1){
            ar[cntr]=i;
            cntr++;
        }
    }
    cout<<cntr<<" "<<ar[cntr-1];
    ll cnt=0;
    for(int i=2;i<=MX1;i++){
        cntr+=maaghsoms()
    }
}
