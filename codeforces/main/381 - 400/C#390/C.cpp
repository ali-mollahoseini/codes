#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n;
int ar[200];
pair<int,int> pii[200];
int main(){
    cin>>n;
    bool tf=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]!=0){
            tf=1;
        }
    }
    if(!tf){
        cout<<"NO"<<endl;
        return 0;
    }
    int cntr=0;
    for(int i=0;i<n;){
        pii[cntr].first=i+1;
        if(i==0&&ar[i]==0){
            while(ar[i]==0&&i<n-1){
                i++;
            }
        }
        i++;
        while(ar[i]==0&&i<n){
            i++;
        }
        pii[cntr].second=i;
        cntr++;
    }
    cout<<"YES"<<endl;
    cout<<cntr<<endl;
    for(int i=0;i<cntr;i++){
        cout<<pii[i].first<<" "<<pii[i].second<<endl;
    }
}
