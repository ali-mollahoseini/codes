/*
ID: ali.mol1
LANG: C++
TASK: ratios
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
const int MX2= 39;
const int inf=1000*1000*1000;
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");

int n,sum[2];
int ratios[4][3];
int halat[MX1][MX1][MX1];
int zarib[3];
int check(int a,int b,int c){
    int tmp=1;
        if(ratios[0][0]){
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if(a%ratios[0][0]==0){
                tmp=a/ratios[0][0];
            }
        }else if(ratios[0][1]){
            if(b%ratios[0][1]==0){
                tmp=a/ratios[0][1];
            }
        }else if(ratios[0][2]){
            if(c%ratios[0][2]==0){
                tmp=a/ratios[0][2];
            }
        }
        if(ratios[0][1]==(double)b/tmp && ratios[0][2]==(double)c/tmp && ratios[0][0]==(double)a/tmp){
            return tmp;
        }
    return 0;
}

int main (){
    sum[0]=inf;
    sum[1]=inf;
    for(int i=0;i<4;i++){
        fin>>ratios[i][0]>>ratios[i][1]>>ratios[i][2];
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                if(i+j+k){
                        //cout<<i<<endl;
                    int tmp[3];
                    tmp[0]=i*ratios[1][0]+j*ratios[2][0]+k*ratios[3][0];
                    tmp[1]=i*ratios[1][1]+j*ratios[2][1]+k*ratios[3][1];
                    tmp[2]=i*ratios[1][2]+j*ratios[2][2]+k*ratios[3][2];
                    int ans=check(tmp[0],tmp[1],tmp[2]);
                    if(ans!=0){
                        cout<<ans<<endl;
                        halat[i][j][k]=ans;
                    }
                }
            }
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                if(halat[i][j][k]!=0){
                    if(i+j+k<sum[0]){
                        zarib[0]=i;
                        zarib[1]=j;
                        zarib[2]=k;
                        sum[0]=i+j+k;
                        sum[1]=halat[i][j][k];
                    }else if(i+j+k==sum[0]){
                        if(halat[i][j][j]<sum[1]){
                            sum[1]=halat[i][j][k];
                            zarib[0]=i;
                            zarib[1]=j;
                            zarib[2]=k;
                        }
                    }
                }
            }
        }
    }
    if(sum[0]!=inf){
        fout<<zarib[0]<<" "<<zarib[1]<<" "<<zarib[2]<<" "<<sum[1]<<endl;
    }else{
        fout<<"NONE"<<endl;
    }
}
