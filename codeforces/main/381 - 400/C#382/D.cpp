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
const int MX2= 1000*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n;
bool prime(ll x){
    for(ll i=2;i*i<=x; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n;

    if(prime(n)){
        cout<<1;
    }else{
        if(n%2==0){
            cout<<2;
        }else{
            if(prime(n-2)==1){
                cout<<2;
            }else{
                cout<<3;
            }
        }
    }
}
