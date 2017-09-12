#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int c,v[2],a,l;
int ar[MX1][MX1];
//////bool ar[MX1][MX1];
int main(){
    cin>>c>>v[0]>>v[1]>>a>>l;
    int x=v[0];
    int cntr=0;
    while(c){
        if(cntr!=0){
            c+=l;
        }
        c-=x;
        if(c<0){
            c=0;
        }
        x+=a;
        if(x>v[1]){
           x=v[1];
        }
        cntr++;
    }
    cout<<cntr<<endl;
}
