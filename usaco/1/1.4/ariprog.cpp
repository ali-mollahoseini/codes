/*
ID: ali.mol1
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");

int main (){
    int n,m;
    bool exist[125004];
    fin>>n>>m;
    memset(exist,0,sizeof(exist));
    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            exist[i*i+j*j]=1;
        }
    }
    vector<pair<int ,int > > vec;
    bool tf2=0;
    for(int i=0;i<m*m*2;i++){
        if(exist[i]){
            for(int j=1;j<m*m*2;j++){
                if(j*(n-1)+i>m*m*2+5) break;
                bool tf=1;
                for(int k=0;k<n;k++){
                    if(!exist[k*j+i]){
                        tf=0;
                        break;
                    }
                }
                if(tf==1){
                    vec.push_back({j,i});
                    tf2=1;
                }
            }
        }
    }
    sort(vec.begin(),vec.end());
    if(tf2==0){
        fout<<"NONE"<<endl;
    }else{
        for(int i=0;i<vec.size();i++){
            fout<<vec[i].second<<" "<<vec[i].first<<endl;
        }
    }
}
