/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
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
const int MX1=101;
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000*1000*10;
ifstream fin ("humble.in");
ofstream fout ("humble.out");

ll n,k;
ll last_p[MX1];
ll p[MX1];
vector<ll> hum;
int xth;
map<ll,bool> top_k;
ll min_ll(ll a,ll b){
    if(a>b){
        return b;
    }
    return a;
}
int main (){
    fin>>n>>k;
    xth=n;
    for(int i=0;i<n;i++){
        fin>>p[i];
        top_k[p[i]]=1;
        hum.push_back(p[i]);
    }
    sort(p,p+n);
    bool tf=1;
    while(tf){
            tf=0;
        for(map<ll,bool>::iterator it =top_k.begin();it!=top_k.end();it++){
            for(int j=0;j<n;j++ ){
                if(p[j]*it->first<p[n-1] && top_k[p[j]*it->first]==0 ){
                    top_k[p[j]*it->first]=1;
                    tf=1;
                    xth++;
                    hum.push_back(p[j]*it->first);
                }
            }
        }
    }
    sort(hum.begin(),hum.end());
    for(xth;xth<=k;xth++){
        ll mn=0x7FFFFFFF;
        ll minp;
        for(int i=0;i<n;i++){
            for(int j=last_p[i];j<xth;j++){
                if((double)hum[j]*p[i]>hum[xth-1]){
                    //if(hum[j]p[i]){
                        mn=min_ll(mn,hum[j]*p[i]);
                        last_p[i]=j;
                        break;
                    //}
                }else{
                }
            }
        }
        hum.push_back(mn);
    }
    for(int i=80000;i<k;i++){
        cout<<hum[i]<<endl;
    }
    fout<<hum[k-1]<<endl;
}
