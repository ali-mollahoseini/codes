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
int s, v1, v2, t1, t2;
int main(){
    cin>>s>>v1>>v2>>t1>>t2;
    int sum[2];
    sum[0]=v1*s+t1*2;
    sum[1]=v2*s+t2*2;
    if(sum[0]<sum[1]){
        cout<<"First"<< endl;
    }else if(sum[0]>sum[1]){
        cout<<"Second"<<endl;
    }else {
        cout<<"Friendship"<<endl;
    }
}
