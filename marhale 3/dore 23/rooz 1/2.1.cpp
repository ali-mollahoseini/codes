#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10271;
int  poww(int a,int b){
    int ans=1;
    int tmp=b;
    while(tmp){
        ans*=a;
        tmp-=1;
    }
    return ans;
}
set<vector<int> >  num;
int main(){
    int a=1 << 16;
    for(int i=0;i<a;i++){
        int ara[4];
        int arb[4];
        ara[0]=0;ara[1]=0;ara[2]=0;ara[3]=0;
        arb[0]=0;arb[1]=0;arb[2]=0;arb[3]=0;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int tmp=j*4+k;
                int x=poww(2,tmp);
                ara[k]+=(i/x)%2;
                arb[j]+=(i/x)%2;
            }
        }
        vector<int> vec;
        for(int j=0;j<4;j++){
            if(i==7){
                cout<<ara[j]<<" "<<arb[j];
            }
            vec.push_back(ara[j]);
            vec.push_back(arb[j]);
        }
        num.insert(vec);
    }
    cout<<num.size();
    long long w=67944169954050625;
    w%=delta;
    cout<<w;
}
