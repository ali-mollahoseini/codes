#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=2*100*1000+100;
const int MX2= 2*1000+100;
const int inf=2*1000*1000*100;
ll n,m,k;
ll x,s;
ll ft[MX1],fgem[MX1];
ll sm[MX1],sgem[MX1];

ll bin_srch(ll money){
    if (money ==0){
        return 0;
    }
    ll fst =-1;
    ll lst =k-1;
    while(fst<lst){
        ll mid=(fst+lst+1)/2;
        if(sgem[mid]>money){
            lst=mid-1;
        }else{
            fst=mid;
        }
    }
    if(lst<0){return 0;}
    return sm[lst];
}
int main(){
    cin>>n>>m>>k;
    cin>>x>>s;
    for(ll i=0;i<m;i++){
        cin>>ft[i];
    }
    for(ll i=0;i<m;i++){
        cin>>fgem[i];
    }
    for(ll i =0 ;i<k;i++){
        cin>>sm[i];
    }
    for(ll i =0 ;i<k;i++){
        cin>>sgem[i];
    }
    //cout<<bin_srch(s);
    ll mn=x*max(n-bin_srch(s),0LL);
    for(ll i=0;i<m;i++){
        ll left=s-fgem[i];
        if(left<0){
            continue;
        }
        //cout<<1<<endl;
        mn =min(mn,ft[i]*max(n-bin_srch(left),0LL));
    }
    cout<<mn;
}
