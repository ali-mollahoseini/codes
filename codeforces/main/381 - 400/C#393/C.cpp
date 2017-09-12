#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n;
int ar[MX2];
bool b[MX2],used[MX2];
int main(){
    cin>>n;
    int ans=0;
    for(int  i =0;i<n;i++){
        cin>>ar[i];
        ar[i]--;
    }
    int sum=0;
    for(int  i =0;i<n;i++){
        cin>>b[i];
        sum+=b[i];
    }
    int cntr=0;
    for(int i=0;i<n;i++){
        int fst=i;
        if(used[i]==1){
            continue;
        }
        cntr++;
        //cout<<i<<endl;
        used[i]=1;
        int nex=ar[i];
        bool tf=1;
        while(tf){
            if(nex==fst){
                tf=0;
                continue;
            }
            used[nex]=1;
            nex=ar[nex];
        }
    }
    //cout<<cntr<<endl;
    if(sum%2==0){
        if(cntr==1){
            cntr--;
        }
        cout<<cntr+1;
    }else{
        if(cntr==1){
            cntr--;
        }
        cout<<cntr;
    }
}
