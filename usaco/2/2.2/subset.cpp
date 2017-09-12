/*
ID: ali.mol1
LANG: C++
TASK: subset
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
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("subset.in");
ofstream fout ("subset.out");

int n,ans;
ll ar[50][800];

int poww(int a,int b){
    int ans=1;
    while(b!=0){
        ans*=a;
        b--;
    }
    return ans;
}
int main (){
    ar[1][0]=1;
    ar[1][1]=1;
    fin>>n;
    if(n%4==3||n%4==0){
        for(int i=2;i<=n;i++){
            ll zarb=i*(i+1)/2;
            for(int j=0;j<i;j++){
                ar[i][j]=ar[i-1][j];
            }
            for(int j=i;j<=zarb;j++){
                ar[i][j]=ar[i-1][j]+ar[i-1][j-i];
            }
        }
        ll zarb=n*(n+1)/4;
        fout<<ar[n][zarb]/2<<endl;
    }else{
        fout<<0<<endl;
    }

}
