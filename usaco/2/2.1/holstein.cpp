/*
ID: ali.mol1
LANG: C++
TASK: holstein
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
const int MX1=25+20;
const int inf=1000*1000*1000;
int n,fdtp,ar[MX1][MX1],mn[MX1],sum[MX1];
int tmp[3];
#define inf 1000*1000*1000
ifstream fin ("holstein.in");
ofstream fout ("holstein.out");
int main (){
    int mnscoop=inf,ans,mnazaans=inf;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>mn[i];
    }
    fin>>fdtp;
    for(int i=0;i<fdtp;i++){
        for(int j=0;j<n;j++){
            fin>>ar[i][j];
        }
    }
    for(int i=0;i<fdtp;i++){
        for(int j=0;j<n;j++){
            sum[i]+=ar[i][j];
        }
    }
    int x= 1 << fdtp;
    for(int i=0;i<x;i++){
        int each[MX1];bool tf=1;int scoop=0;int mnaza=inf;
        memset(each,0,sizeof(each));
        for(int j=0;j<fdtp;j++){
            if((i >> j) & 1){
                scoop++;
                mnaza=min(mnaza,sum[j]);
                for(int k=0;k<n;k++){
                    each[k]+=ar[j][k];
                }
            }
        }
        for(int j=0;j<n;j++){
            if(mn[j]>each[j]){
                tf=0;
                break;
            }
        }
        if(tf && scoop<mnscoop){
            mnscoop=scoop;
            ans=i;
            mnazaans=mnaza;
        }else if(tf && scoop==mnscoop && mnazaans>mnaza){
            ans=i;
            mnazaans=mnaza;
        }
    }
    fout<<mnscoop<<" ";
    //cout<<mnscoop<<" ";
    int cntr=1;
    for(int i=0;i<fdtp;i++){
        if((ans>>i) & 1){
            if(cntr==mnscoop){
                cntr++;
                fout<<i+1<<endl;
                //cout<<i+1<<endl;
            }else{
                    cntr++;
                fout<<i+1<<" ";
                //cout<<i+1<<" ";
            }
        }
    }
}
