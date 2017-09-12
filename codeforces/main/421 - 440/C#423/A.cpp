#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int one,tow,towr,n,den;
int ar[MX1][MX1];
//////bool ar[MX1][MX1];
int main(){
    cin>>n>>one>>tow;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if (tmp==1){
            if(one>0){
                one--;
            }else if(tow>0){
                tow--;
                towr++;
            }else if(towr>0){
                towr--;
            }else{
                den++;
            }
        }else{
            if(tow>0){
                tow--;
            }else{
                den+=2;
            }
        }
    }
    cout<<den;
}
