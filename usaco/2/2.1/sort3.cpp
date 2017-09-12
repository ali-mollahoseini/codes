/*
ID: ali.mol1
LANG: C++
TASK: sort3
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=1000+10;
int n,ar[MX1],num[4],nabejae[4][4];
int tmp[3];
#define inf 1000*1000*1000
ifstream fin ("sort3.in");
ofstream fout ("sort3.out");

int main (){
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>ar[i];
        num[ar[i]]++;
    }
    for(int i=0;i<n;i++){
        if(ar[i]==1){
            if(i>=num[1]&&i<num[1]+num[2]){
                nabejae[1][2]++;
            }
            if(i>=num[1]+num[2]){
                nabejae[1][3]++;
            }
        }else if(ar[i]==2){
            if(i<num[1]){
                nabejae[2][1]++;
            }
            if(i>=num[1]+num[2]){
                nabejae[2][3]++;
            }
        }else if(ar[i]==3){
            if(i<num[1]){
                nabejae[3][1]++;
            }
            if(i>=num[1]&&i<num[1]+num[2]){
                nabejae[3][2]++;
            }
        }
    }
    int sum=0;
    cout<<num[1]<<" "<<num[2]<<" "<<num[3]<<endl;
    cout<<nabejae[1][2]<<" "<<nabejae[2][1]<<" "<<nabejae[2][3]<<" "<<nabejae[3][2]<<" "<<nabejae[1][3]<<" "<<nabejae[3][1]<<endl;
    tmp[0]=min(nabejae[1][2],nabejae[2][1]);
    tmp[1]=min(nabejae[2][3],nabejae[3][2]);
    tmp[2]=min(nabejae[1][3],nabejae[3][1]);
    nabejae[1][2]-=tmp[0];nabejae[2][1]-=tmp[0];
    nabejae[2][3]-=tmp[1];nabejae[3][2]-=tmp[1];
    nabejae[1][3]-=tmp[2];nabejae[3][1]-=tmp[2];
    sum+=nabejae[1][2]+nabejae[2][1]+nabejae[1][3]+nabejae[3][1]+nabejae[2][3]+nabejae[3][2];
    cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<" "<<sum;
    fout<<tmp[0]+tmp[1]+tmp[2]+sum*2/3<<endl;
}
