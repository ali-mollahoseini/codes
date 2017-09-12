#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10271;

int g(int a){
    int tmp= a;
    int x=1;
    int sum=0;
    for(int i=1;i<a;i++){
        for(int j=1;j<a;j++){
            int tmpj=j;
            while(tmpj){
                if(tmpj%2==0){
                    x*=2;
                    tmpj/=2;
                }else if (tmpj%2==1){
                    x*=3;
                    tmpj/=2;
                }
            }
            x*=i;
            sum+=x;
            x=1;
        }
    }
    return sum;
}
int main(){
        for(int i=1;i<10;i++){
            cout<<i<<" "<<g(i)<<endl;
        }
}
