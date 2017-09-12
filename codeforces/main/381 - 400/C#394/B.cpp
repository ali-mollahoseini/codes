#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
ll n,m,k;
ll sum(ll mn,ll mx){
    if(mn>mx){
        return 0;
    }
    return (mn+mx)*(mx-mn+1)/2;
}
bool make(int i){
    ll l=k-1,r=n-k;
    //cout<<r<< " "<<l<<endl;;
    ll tmp=i;
    if(l>=i){
        tmp+=sum(1,i-1);
    }else{
        tmp+=sum(i-l,i-1);
    }
    if(r>=i){
        tmp+=sum(1,i-1);
    }else{
        tmp+=sum(i-r,i-1);
    }//cout<<i<<" "<<tmp<<endl;
    if(tmp<=m-n){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    cin>>n>>m>>k;
    int fst =0, lst=2000*1000*1000;
    while(fst<lst){
        ll mid=(fst+lst+1)/2;
        if(make(mid)){
            fst=mid;
        }else{
            lst=mid-1;
        }
    }
    cout<<fst+1;
}
