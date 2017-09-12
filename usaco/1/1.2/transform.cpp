/*
ID: ali.mol1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ofstream fout ("transform.out");
ifstream fin ("transform.in");
vector<char> vec;
bool b[5000];
int n,s,arin[10][10],arout[10][10],idle,busy;
bool DR90(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    int ab[sizea][sizea]={0};
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[j][sizea-i-1]=a[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            (ab[i][j]==b[i][j])?j=j:tf=false;
        }
    }
    if(tf){
        return true;
    }else{
        return false;
    }
}
bool DR180(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    int ab[sizea][sizea]={0};
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[sizea-i-1][sizea-j-1]=a[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            (ab[i][j]==b[i][j])?j=j:tf=false;
        }
    }
    if(tf){
        return true;
    }else{
        return false;
    }
}
bool DR270(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    int atmp[10][10];

    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            atmp[i][j]=a[i][j];
        }
    }
    int ab[sizea][sizea]={0};
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[j][sizea-i-1]=atmp[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            atmp[j][sizea-i-1]=ab[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[j][sizea-i-1]=atmp[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            (ab[i][j]==b[i][j])?j=j:tf=false;
        }
    }
    if(tf){
        return true;
    }else{
        return false;
    }
}
bool reflect(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    int ab[sizea][sizea]={0};
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[i][sizea-j-1]=a[i][j];
        }
    }
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            (ab[i][j]==b[i][j])?j=j:tf=false;
        }
    }
    if(tf){
        return true;
    }else{
        return false;
    }
}
bool combination(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    int ab[10][10]={0};
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            ab[i][sizea-j-1]=a[i][j];
        }
    }
    if(DR90(ab,arout,sizea)||DR180(ab,arout,sizea)||DR270(ab,arout,sizea)){

        return true;
    }else{
        return false;
    }
}
bool same(int a[10][10],int b[10][10],int sizea){
    bool tf=true;
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizea;j++){
            (a[i][j]==b[i][j])?j=j:tf=false;
        }
    }
    if(tf){
        return true;
    }else{
        return false;
    }
}
int main (){
    fin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            fin>>c;
            (c=='@')?arin[i][j]=1:arin[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            fin>>c;
            (c=='@')?arout[i][j]=1:arout[i][j]=0;
        }
    }
    if(DR90(arin,arout,n)){
        fout<<"1"<<endl;
    }else if(DR180(arin,arout,n)){
        fout<<"2"<<endl;
    }else if(DR270(arin,arout,n)){
        fout<<"3"<<endl;
    }else if(reflect(arin,arout,n)){
        fout<<"4"<<endl;
    }else if(combination(arin,arout,n)){
        fout<<"5"<<endl;
    }else if(same(arin,arout,n)){
        fout<<"6"<<endl;
    }else{
        fout<<"7"<<endl;
    }

    return 0;
}
