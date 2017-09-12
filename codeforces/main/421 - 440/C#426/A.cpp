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
const int inf=2*1000*1000*1000*1000*1000*1000;
char a[2];
int n;
char cw[4]={'^','>','v','<'};
char ccw[4]={'^','<','v','>'};
int main(){
    cin>>a[0]>>a[1];
    cin>>n;
    int p[2];
    for(int i=0;i<4;i++){
        if(a[0]==cw[i]){
            p[0]=i;
        }
        if(a[0]==ccw[i]){
            p[1]=i;
        }
    }
    n%=4;
    if(ccw[(p[1]+n)%4]==a[1]&&cw[(p[0]+n)%4]!=a[1]){
        cout<<"ccw";
    }else if(cw[(p[0]+n)%4]==a[1]&&ccw[(p[1]+n)%4]!=a[1]){
        cout<<"cw";
    }else{
        cout<<"undefined";
    }
}
