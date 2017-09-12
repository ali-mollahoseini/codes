/*
ID: ali.mol1
LANG: C++
TASK: nocows
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
const int MX1=400;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("nocows.in");
ofstream fout ("nocows.out");

int dp[MX1][MX1];
int n,k;

int poww(int a,int b){
    int ans=1;
    while(b!=0){
        ans*=a;
        b--;
    }
    return ans;
}
void dp_m(int a){
    int d=1,tmp=a-1;
    bool tf=1;
    while(tf){
        if(a>=2*d-1){

            for(int i=1;i<tmp;i+=2){
                int num[2];
                num[0]=tmp-i;
                num[1]=i;
                for(int j=1;j<=d-1;j++){
                    dp[a][d]+=dp[num[0]][d-1]*dp[num[1]][j];
                    dp[a][d]+=dp[num[0]][j]*dp[num[1]][d-1];
                    dp[a][d]%=9901;
                }
                dp[a][d]-=dp[num[0]][d-1]*dp[num[1]][d-1];
                if(dp[a][d]<0){
                    dp[a][d]+=9901;
                }
            }
            if(a+1==poww(2,d)){
                dp[a][d]=1;
            }
        }
        d++;
        if(a<2*d-1){
            tf=0;
        }
    }
}
int main (){

    fin>>n>>k;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        dp_m(i);
    }
    for(int i=1;i<=n;i+=2){cout<<i<<"    ";
        for(int j=30;j<=40;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    fout<<dp[n][k]<<endl;
}
