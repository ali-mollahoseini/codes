//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000+100;
int ar[200];
int main(){
    int  n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int bghi=0, cntr=0;
    int i=0;
    while(i<n&&cntr<k){
        cntr+=min(bghi+ar[i],8);
        if(cntr>=k){
            break;
        }else{
            bghi=max(0,bghi+ar[i]-8);
        }
        i++;
    }
    if(cntr<k){
        cout<<-1<<endl;
    }else {
        cout<<i+1<<endl;
    }
}
