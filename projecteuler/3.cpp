#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");



vector<int> prime;

int main(){
    ll ans=600851475143;
    int a=sqrt(600851475143);
    a+=10;
    cout<<a<<endl;
    for(int i=2;i<a;i++){
        bool tf=1;
        for(int j=2;j*j<i;j++){
            if(i%j==0){
                tf=0;break;
            }
        }
        if(tf==1){
            prime.push_back(i);
        }
    }
    ll mx=1;
    for(int i=0;i<prime.size();i++){
        while(ans%prime[i]==0){
            mx=prime[i];
            ans/=prime[i];
        }
    }
    cout<<mx<<endl;
}
