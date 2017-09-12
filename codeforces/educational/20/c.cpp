//in the name of god
//© by ali mollahoseini from 2016-2017 :D
#include <iostream>
#define ll long long
const int inf= 0x7FFFFFFF;

using namespace std;
ll n,k;
ll sol(ll sum,ll num){
    if(num>1000000){
        return -1;
    }
    ll tmp=(num+1)*num/2;
    ll mx=-1;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0){
            if(i>mx){
                if(i*tmp<=sum){
                    mx=i;
                }
            }
            if (sum/i>mx){
                //cerr<<sum/i<<" "<<tmp<<" " ;
                if((sum/i)*tmp<=sum && (sum/i)*tmp>0 ){
                    mx=sum/i;
                }
            }
        }
    }
    return mx;
}
int main(){
    cin>>n>>k;
    ll ans=sol(n,k);
    if(ans!=-1){
        ll tmp=(k)*(k-1)/2;
        ll w=n/ans;
        for(ll i =1;i<k;i++){
            cout<<i*ans<<" ";
        }
        cout<<(w-tmp)*ans;
    }else {
        cout<<ans<<endl;
    }
}
