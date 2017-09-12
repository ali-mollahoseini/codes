/*
ID: ali.mol1
LANG: C++
TASK: wormhole
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=13;
#define inf 1000*1000*1000
ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");


int n,x[MX1],y[MX1],r[MX1],par[MX1];
bool cycl(){
    for(int i=1;i<=n;i++){
        int x=i;
        for(int j=1;j<=n;j++){
            x=r[par[x]];
        }
        if(x!=0){
            return 1;
        }
    }
    return 0;
}
void rightone(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[j]>x[i] && y[i]==y[j]&&(r[i]==0||x[r[i]]>x[j])){
                r[i]=j;
            }
        }
    }
}
int ans(){
    int pos=0,sum=0;
    for(int i=1;i<=n;i++){
        if(par[i]==0){
            pos=i;
            break;
        }
    }
    if(pos==0){
        if(cycl())return 1;
        return 0;
    }
    for(int i=pos+1;i<=n;i++){
        if(par[i] == 0){
            par[pos]=i;
            par[i]=pos;
            sum+=ans();
            par[pos] = par[i] = 0;
        }
    }
    return sum;
}
int main (){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>x[i]>>y[i];
    }
    rightone();
    fout<<ans()<<endl;
}
