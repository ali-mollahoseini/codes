/*
ID: ali.mol1
LANG: C++
TASK: numtri
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
const int MX1=1005;
#define inf 1000*1000*1000
ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

int r,inp[MX1][MX1];
void dp(){
    for(int i=r-2;i>-1;i--){
        for(int j=0;j<i+1;j++){
            inp[i][j]+=max(inp[i+1][j],inp[i+1][j+1]);
        }
    }
}
int main (){
    fin>>r;
    for(int i=0;i<r;i++){
        for(int j=0;j<i+1;j++){
            fin>>inp[i][j];
        }
    }
    dp();
    fout<<inp[0][0]<<endl;
}
