#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10733;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

ll ar[31];
int check(int a){
    bool tf=1;
    for(int i=1;i<30;i++){
        if(a%ar[i]==0){
            tf=0;
        }
    }
    return tf;
}
int main(){
    int ar[33];
    int sorat[33];
    for(int i=0;i<33;i++){
        ar[i]=i+1;
    }
    for(int i=0;i<33;i++){
        sorat[i]=i+34;
    }
    int cntr=0;
    for(int i =0;i<33;i++){
        for(int j=0;j<33;j++){
            int x=__gcd(ar[j],sorat[i]);
            ar[j]/=x;
            sorat[i]/=x;
        }
    }
    ll ans=1;
    for(int i=0;i<33;i++){
        ans*=sorat[i];
    }
    cout<<ans%delta<<endl;
}
