#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=101;
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n,x,y;
bool ok(int rnk,int s){
    int tmp=(s/50)%475;
    bool ans=0;
    for(int i=0;i<25;i++){
        tmp= (tmp*96+42)%475;
        if(tmp+26==rnk){
            ans=1;
            break;
        }
    }
    return ans;
}
int main(){
    int ans=0;
    bool tf=0;
    cin>>n>>x>>y;
    int tmp=x;
    while(tmp>=y){
        if(ok(n,tmp)){
            ans=0;
            tf=1;
            break;
        }
        tmp-=50;
    }
    if(tf==0){
        int cntr=1;
        while(tf==0){
            if(ok(n,x+cntr*50)){
                ans=(cntr+1)/2;
                tf=1;
                break;
            }
            cntr++;
        }
    }
    cout<<ans;
}
