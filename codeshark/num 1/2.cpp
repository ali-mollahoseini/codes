//in the name of god;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10103;
ofstream fout("1.txt");

vector<int> ones[21];
ll tables;
ll poww(ll a,int b){
    ll ans=1;
    while(b){
        ans*=a;
        ans%=delta;
        b-=1;
    }
    return ans;
}


int first(ll a){
    int ans=0;
    while(a){
        ans++;
        if(a%2==1){
            return ans;
        }
        a/=2;
    }
    return ans;
}


int last(ll a){
    int ans=0;
    int cntr=0;
    while(a){
        cntr++;
        if(a%2==1){
            ans=cntr;
        }
        a/=2;
    }
    return ans;
}
int adad(ll a){
    int ans=0;
    while(a){
        if(a%2==1){
            ans++;
        }
        a/=2;
    }
    return ans;
}

/*ll tarkib(int r,int n){
    int ar[n-r],ar1[n-r];
    for(int i=0;i<n-r;i++){
        ar[i]=i+r+1;
        ar1[i]=i+1;
    }
    for(int i=0;i<n-r;i++){
        for(int j=0;j<n-r;j++){
            int x=__gcd(ar[i],ar1[j]);
            ar[i]/=x;
            ar1[j]/=x;
        }
    }
    ll ans=1;
    for(int i=0;i<n-r;i++){
        ans*=ar[i];
    }
    return ans;
}*/

int main(){
    cout<<fixed<<setprecision(6);
    double n=13781378;
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=(double)1/i;
        //cout<<double(i/n);
    }
    //ans+=1/n;
    //ans=(double)25/12;
    ans*=(double)n;
    //ans+%=delta;
    cout<<ans<<endl;
    ll tmp=(ll)((double)ans*1000);
    cout<<tmp;
    ll kol=poww(tmp,5);
    cout<<kol%delta;
}
