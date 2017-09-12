/*
ID: ali.mol1
LANG: C++
TASK: combo
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=100+10;
ofstream fout ("combo.out");
ifstream fin ("combo.in");
int n,ans,ans2[2],sum,lim;
int cnt[3],ar[2][3],ar1ans[3][5],ar2ans[3][5];
bool kochektar(int a,int b){
    return (a>b);
}
void set_in(int one,int janeshin[][5]){

}
int main (){
    fin>>n;
    lim=min(n,5);
    fin>>ar[0][0]>>ar[0][1]>>ar[0][2];
    fin>>ar[1][0]>>ar[1][1]>>ar[1][2];
    sum=2*lim*lim*lim;
    set_in(0,ar1ans);
    set_in(1,ar2ans);
    cout<<ar1ans[2][0]<<" "<<ar1ans[2][1]<<" "<<ar1ans[2][2]<<" "<<ar1ans[2][3]<<" "<<ar1ans[2][4]<<endl;
    cout<<ar2ans[2][0]<<" "<<ar2ans[2][1]<<" "<<ar2ans[2][2]<<" "<<ar2ans[2][3]<<" "<<ar2ans[2][4]<<endl;
    for(int r=0;r<3;r++){
        for(int i=0;i<lim;i++){
            for(int j=0;j<lim;j++){
                if(ar1ans[r][i]==ar2ans[r][j]){
                    cnt[r]++;
                    break;
                }
            }
        }
    }
    cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" ";
    sum-=cnt[0]*cnt[1]*cnt[2];
    fout<<sum<<endl;
}
