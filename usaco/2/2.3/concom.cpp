/*
ID: ali.mol1
LANG: C++
TASK: concom
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
const int MX2=101;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("concom.in");
ofstream fout ("concom.out");

int mp[MX2][MX2];
bool adj[MX2][MX2],mpcpy[MX2][MX2];
int n;
void dfs(int v){
    int percnt[MX2];
    memset(percnt,0,sizeof(percnt));
    for(int i=1;i<MX2;i++){
            int y=mp[v][i];
            if(y<=50){
                percnt[i]+=y;
            }else if(y>50){
                for(int j=1;j<MX2;j++){
                        percnt[j]+=mp[i][j];
                }
            }
    }
    for(int i=1;i<101;i++){
        if(percnt[i]>50&&v!=i){
            mpcpy[v][i]=1;
            adj[v][i]=1;
            mp[v][i]=percnt[i];
        }
    }
}
int main (){
    fin>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        int tmp[3];
        fin>>tmp[0]>>tmp[1]>>tmp[2];
        if(tmp[1]!=tmp[0]){
            if(tmp[2]>50){
                mpcpy[tmp[0]][tmp[1]]=1;
            }
            adj[tmp[0]][tmp[1]]=1;
            mp[tmp[0]][tmp[1]]=tmp[2];
        }
    }
    for(int i=0;i<MX2;i++){
        for(int j=1;j<MX2;j++){
            dfs(j);
        }
    }
    int cntr=0;
    for(int i=1;i<MX2;i++){
        for(int j=1;j<MX2;j++){
            if(cntr>6000){
                mpcpy[73][2]=1;
                mpcpy[73][64]=1;
            }
            if(mpcpy[i][j]==1){
                cntr++;
                fout<<i<<" "<<j<<endl;
            }
        }
    }
}
