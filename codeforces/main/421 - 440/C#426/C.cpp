//in the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000*1000*1000+7;
const int MX1 = 5*1000*1000+100;
const int MX2 = 2000*1000+100;
const int inf = 2*1000*1000*1000+7;
ll def[40000+100];
ll n;
vector<int> p;
void seive(){
    ll mx=40000;
    for(ll i=2;i<mx;i++){
        if(def[i]==0){
            for(ll j=i*i;j<mx;j+=i){
                //cout<<1;
                def[j]=i;
            }
        }
    }
}
int main(){
    cin>>n;
    seive();
    for(ll i=2;i<40000;i++){
        if(def[i]==0){
            p.push_back(i);
            //cout<<i<<" ";
        }
    }
    for(ll i=0;i<n;i++){
    //cout<<1;
        bool tf=1;
        ll a,b;
        cin>>a>>b;
        for(int j=0;j<p.size();j++){
            ll cnta=0,cntb=0;
            while(a%p[j]==0){
                a/=p[j];
                cnta++;
            }
            while(b%p[j]==0){
                b/=p[j];
                cntb++;
            }
            //cout<<cnta<<" "<<cntb<<endl;;
            if((cnta+cntb)%3==1||(cnta+cntb)%3==2){
                tf=0;
                break;
            }else{
                if(abs(cnta-cntb)>(cnta+cntb)/3){
                    tf=0;
                    break;
                }
            }
        }
        if(tf==1){
            cout<<"YES"<<endl;;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
