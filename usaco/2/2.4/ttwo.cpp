/*
ID: ali.mol1
LANG: C++
TASK: ttwo
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
ifstream fin ("ttwo.in");
ofstream fout ("ttwo.out");



int desk[10][10];
int jahat[2];
int pos[2];
map<pair<pair<int ,int>,pair<int,int> >,bool> visited;
void inp();

int main (){
    inp();
    int cntr=0;
    for(int i=0;i<1000;i++){
        if(visited[{{jahat[0],jahat[1]},{pos[0],pos[1]}}]==0){
            cout<<i+1;
            visited[{{jahat[0],jahat[1]},{pos[0],pos[1]}}]=1;
        }else{
            break;
        }
        for(int j=0;j<10;j++){
            cout<<endl;
            for(int k=0;k<10;k++){
                cout<<desk[j][k]<<" ";
            }
        }
        int tmp[2]={pos[0]/10,pos[0]%10};
        if(jahat[0]==2){
            if(desk[tmp[0]+1][tmp[1]]!=3  && tmp[0]!=9){
                desk[tmp[0]+1][tmp[1]]=1;
                desk[tmp[0]][tmp[1]]=0;
                pos[0]+=10;
            }else{
                jahat[0]++;
                jahat[0]%=4;
            }
        }else if(jahat[0]==1){
            if(desk[tmp[0]][tmp[1]+1]!=3 && tmp[1]!=9){
                desk[tmp[0]][tmp[1]+1]=1;
                desk[tmp[0]][tmp[1]]=0;
                pos[0]+=1;
            }else{
                jahat[0]++;
                jahat[0]%=4;
            }
        }else if(jahat[0]==0){
            if(desk[tmp[0]-1][tmp[1]]!=3 && tmp[0]!=0){
                desk[tmp[0]-1][tmp[1]]=1;
                desk[tmp[0]][tmp[1]]=0;
                pos[0]-=10;
            }else{
                jahat[0]++;
                jahat[0]%=4;
            }
        }else if(jahat[0]==3){
            if(desk[tmp[0]][tmp[1]-1]!=3 && tmp[1]!=0){
                desk[tmp[0]][tmp[1]-1]=1;
                desk[tmp[0]][tmp[1]]=0;
                pos[0]-=1;
            }else{
                jahat[0]++;
                jahat[0]%=4;
            }
        }



        int pmp[2]={pos[1]/10,pos[1]%10};
        if(jahat[1]==2){
            if(desk[pmp[0]+1][pmp[1]]!=3 && pmp[0]!=9){
                desk[pmp[0]+1][pmp[1]]=2;
                desk[pmp[0]][pmp[1]]=0;
                pos[1]+=10;
            }else{
                jahat[1]++;
                jahat[1]%=4;
            }
        }else if(jahat[1]==1){
            if(desk[pmp[0]][pmp[1]+1]!=3 && pmp[1]!=9){
                desk[pmp[0]][pmp[1]+1]=2;
                desk[pmp[0]][pmp[1]]=0;
                pos[1]+=1;
            }else{
                jahat[1]++;
                jahat[1]%=4;
            }
        }else if(jahat[1]==0){
            if(desk[pmp[0]-1][pmp[1]]!=3 && pmp[0]!=0){
                desk[pmp[0]-1][pmp[1]]=2;
                desk[pmp[0]][pmp[1]]=0;
                pos[1]-=10;
            }else{
                jahat[1]++;
                jahat[1]%=4;
            }
        }else if(jahat[1]==3){
            if(desk[pmp[0]][pmp[1]-1]!=3 && pmp[1]!=0){
                desk[pmp[0]][pmp[1]-1]=2;
                desk[pmp[0]][pmp[1]]=0;
                pos[1]-=1;
            }else{
                jahat[1]++;
                jahat[1]%=4;
            }
        }
        cout<<endl;
        if(pos[0]==pos[1]){
            cntr=i+1;
            break;
        }
    }
    fout<<cntr<<endl;
}
void inp(){
    for(int i=0;i<10;i++){
        string tmp;
        fin>>tmp;
        for(int j=0;j<10;j++){
            if(tmp[j]=='*'){
                desk[i][j]=3;
            }else if(tmp[j]=='.'){
                desk[i][j]=0;
            }else if(tmp[j]=='C'){
                desk[i][j]=1;
                pos[0]=10*(i)+j;
            }else {
                desk[i][j]=2;
                pos[1]=10*(i)+j;
            }
        }
    }
}
