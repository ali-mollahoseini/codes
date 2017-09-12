#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000;
int ar[300], z,n ;
vector<int> zar,zes;
int main(){
    cin>>n>>z;
    int mn=inf;
    int cntr=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(!ar[i]){
            zes.push_back(i);
        }
    }
    for(int i=0;i<z;i++){
        int tmp;
        cin>>tmp;
        zar.push_back(tmp);
    }
    sort(zar.begin(),zar.end(),greater<int>());
    for(int i=0;i<z;i++){
        ar[zes[i]]=zar[i];
    }
    bool tf=0;
    for(int i=0;i<n-1;i++){
        if(ar[i]>=ar[i+1]){
            tf=1;
            break;
        }
    }
    if(tf){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}

