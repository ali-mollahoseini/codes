//in the name of god;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10069;
vector<int> ones[21];
ll tables;
int poww(int a,int b){
    int ans=1;
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
    int n=100;
    ll bit=1<<n;
    //cout<<bit;
    for(int i=1;i<bit;i++){

        int tmp=adad(i);
        ones[tmp].push_back(i);
    }
    int s=n*n;
        int alamat=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<ones[i].size();j++){
            int lst=last(ones[i][j]) , fst=n-first(ones[i][j])+1;
            int x=((n-2)*i)+lst+fst;
            int tmp=s-x;
            int halat=poww(2,tmp);
            if(alamat==-1){
                tables-=halat%delta;
            }else{
                tables+=halat%delta;
            }
            tables%=delta;
            while(tables<0){
                tables+=delta;
            }
        }
        alamat*=-1;
    }
    cout<<tables<<endl;
}
