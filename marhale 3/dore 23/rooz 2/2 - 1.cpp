#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int delta = 10181;
const int inf=0x7FFFFFFF;
//ifstream fin ("contact.in");
//ofstream fout ("contact.out");
int aml[1000];
ll poww (ll a,int b){
    int ans=1;
    while(b){
        ans*=a;;
        ans%=delta;
        b--;
    }
    return ans;
}
int tarkib(int a, int b){
}
int main(){
    int ans=poww(5,600);
    for(int i=601;i<1001;i++){
            int tmp=i;
        for(int j=2;j<1000;j++){
            while(tmp%j==0){
                tmp/=j;
                aml[j]++;
            }
        }
    }
    for(int k=0;k<2;k++){
        for(int i=2;i<201;i++){
                int tmp=i;
            for(int j=2;j<1000;j++){
                while(tmp%j==0){
                    tmp/=j;
                    aml[j]--;
                }
            }
        }
    }
    for(int j=2;j<1000;j++){
        while(aml[j]){
            ans*=j;
            ans%=delta;
            aml[j]--;
        }
    }
    cout<<ans;
}
