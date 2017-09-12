/*
ID: ali.mol1
LANG: C++
TASK: inflate
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
const int MX1=10001;
const int MX2= 39;
const int inf=1000*1000*1000;
ifstream fin ("inflate.in");
ofstream fout ("inflate.out");

int dp[MX1];
int a,b,t,n;
int main (){
    fin>>t>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        fin>>a>>b;
        for(int j=0;j<=t;j++){
            if(j-b>-1){
                if(dp[j-b]+a>dp[j]){
                    mx=max(dp[j]=dp[j-b]+a,mx);
                }
            }
        }
    }
    fout<<mx<<endl;
}
