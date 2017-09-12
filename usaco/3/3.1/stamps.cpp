/*
ID: ali.mol1
LANG: C++
TASK: stamps
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
const int MX1= 101;
const int MX2= 2*1000*1000;
const int inf=1000*1000*1000;
ifstream fin ("stamps.in");
ofstream fout ("stamps.out");

int k,n;
int ar[MX1];
int best[MX2];

int main (){
    fin>>k>>n;
    for(int i=0;i<n;i++){
        fin>>ar[i];
    }
    for(int i=1;i<MX2;i++){
        best[i]=inf;
    }
    bool tf=1;
    int cntr=1;
    cout<<k;
    while(tf==1){
        for(int i=0;i<n;i++){
            if(cntr-ar[i]>-1){
                if(best[cntr-ar[i]]+1<best[cntr]){
                    best[cntr]=best[cntr-ar[i]]+1;
                }
            }
        }
        if(best[cntr]>k){
            tf=0;
        }
        //cout<<1;
        cntr++;
    }
    fout<<cntr-2<<endl;
}
