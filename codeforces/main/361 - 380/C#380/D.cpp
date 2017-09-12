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
int n,a,b,k;
string s;
vector<int> vec;
int main(){
    cin>>n>>a>>b>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        vec.push_back((int)s[i]-'0');
    }
    int cntr=0;
    int sum=0;
    for(int i =0 ;i<n;i++){
        if(vec[i]==1){
            cntr=0;
        }else{
            cntr++;
            cntr%=b;
            if(cntr==0){
                sum++;
            }
        }
    }
    sum-=(a-1);
    cout<<sum<<endl;
    cntr=0;
    for(int i =0 ;i<n;i++){
        if(vec[i]==1){
            cntr=0;
        }else{
            cntr++;
            cntr%=b;
            if(cntr==0){
                sum--;
                cout<<i+1<<" ";
                if(sum==0){
                    break;
                }
            }
        }
    }
    cout<<endl;
}
