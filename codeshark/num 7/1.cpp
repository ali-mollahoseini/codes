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
    vector<int> avval;
    for(int i=2;i<100;i++){
        bool tf=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                tf=0;
            }
        }
        if(tf==1){
            avval.push_back(i);
        }
    }
    ll m=0,n=0;
    ll ar[2]={1,1};
    bool tf=1;
    int a=0;
    ll cntr=2;
    for(int i=0;i<avval.size();i++){
        m=avval[i];
        cntr=0;
        tf=1;
        a=0;
        ar[0]=1;ar[1]=1;
        while(tf){
            tf=1;
            ar[a]=(ar[a]+ar[(a+1)%2])%m;
            if(ar[a]==n){
                tf=0;
            }
            if(cntr%(MX1)==0){
                //cout<<cntr<<endl;

            }
            a++;
            a%=2;
            cntr++;
        }
        cout<<m<<" "<<cntr<<endl;
    }
    ll ans =cntr;
    ans%=delta;
    cout<<ans;
}
