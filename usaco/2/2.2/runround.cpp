/*
ID: ali.mol1
LANG: C++
TASK: runround
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
const int MX1=200;
const int inf=1000*1000*1000+1000;
#define inf 1000*1000*1000
ifstream fin ("runround.in");
ofstream fout ("runround.out");

int n,ans=inf;
int ar[9]={1,2,3,4,5,6,7,8,9};
int subar[9];
bool runaround(int to){
    int tmp[11],j=0;
    memset(tmp,0,sizeof(tmp));
    int fst=subar[0];
    for(int i=0;i<to;i++){
        tmp[subar[j]]++;
        if(tmp[subar[j]]>1){
            return false;
        }
        j=(j+subar[j]%to)%to;
    }
    if(subar[0]==subar[j]){
        return true;
    }
    return false;
}
int tonum(int x){
    int ans=0;
    for(int i=0;i<x;i++){
        ans*=10;
        ans+=subar[i];
    }
    return ans;
}
int poww(int a,int b){
    int ans=1;
    while(b!=0){
        ans*=a;
        b--;
    }
    return ans;
}
int one(int a){
    int ans=0;
    while(a){
        ans+=a%2;
        a/=2;
    }
    return ans;
}
int main (){
    fin>>n;
    int tmp=n;
    int num=0;
    while(tmp!=0){
        tmp/=10;
        num++;
    }
    int x= (1 << 9) -1;
    for (int i=0;i<x;i++){
            int ones=one(i);
        if(ones==num||ones==num+1){
            int cntr=0;
            for(int j=0;j<10;j++){
                if((i>>j) & 1){
                    subar[cntr]=ar[j];
                    cntr++;
                }
            }
            do{
                    int tmpans=tonum(ones);
                    if(tmpans==81362){
                    }
                if(runaround(ones)){
                    if(tmpans>n){
                        ans=min(ans,tmpans);
                    }
                }
            }while(next_permutation(subar,subar+ones));
        }
    }
    fout<<ans<<endl;
}
