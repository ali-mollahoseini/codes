#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
ll n,ang;
int ar[3];
double dis;
//ll ar[MX2];
int main(){
    ar[1]=1;
    cin>>n>>ang;
    ar[0]=n;
    dis=inf;
    double ich= ((double)180/n);
    for(int i=1;i<n-1;i++){
        double tmp=((double)ich*i);
        if(abs(ang-tmp)<dis){
            dis=((double)abs(ang-tmp));
            ar[2]=n-i;
        }
    }
    cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2]<<endl;
}
