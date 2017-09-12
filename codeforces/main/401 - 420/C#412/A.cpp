/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n;
ll ar[MX2];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        a%=mod;
        ar[i]=a;
    }
    bool tf=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(tf==1){
                ar[j]=ar[j]+ar[j+1];
                tf=0;
            }else{
                ar[j]=ar[j]-ar[j+1];
                tf=1;
            }
        }
    }
    cout<<ar[0]%mod<<endl;
}
