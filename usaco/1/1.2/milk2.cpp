/*
ID: ali.mol1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ofstream fout ("milk2.out");
ifstream fin ("milk2.in");
string s;
vector<int> vec;
bool b[5000];
int n,ar[5000][2],idle,busy;
int sort_khodam(int x){
    int tmpx=x;
    for(int j=0;j<x;j++){
        for(int i=0;i<tmpx-1;i++){
            if(ar[i][0]>ar[i+1][0]){
                int tmp=ar[i+1][0],tmp2=ar[i+1][1];
                ar[i+1][0]=ar[i][0];
                ar[i][0]=tmp;
                ar[i+1][1]=ar[i][1];
                ar[i][1]=tmp2;
            }
        }
    }
}
int main (){
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>ar[i][0]>>ar[i][1];
    }

    sort_khodam(n);

    for(int i=0;i<n;i++){
        vec.push_back(ar[i][0]);
        vec.push_back(ar[i][1]);
        for(int j=0;j<n;j++){
            if(vec.at(i*2+1)>=ar[j][0]&&vec.at(i*2+1)<ar[j][1]){
                vec.at(i*2+1)=ar[j][1];
            }else if(vec.at(i*2)>=ar[j][0]&&vec.at(i*2)<ar[j][1]){
                vec.at(i*2)=ar[j][0];
                vec.at(i*2+1)=max(ar[j][1],vec.at(i*2+1));
            }

        }
        busy=max(busy,vec.at(i*2+1)-vec.at(i*2));
        cout<<busy<<" ";
    }
    for(int i=0;i<n-1;i++){
        idle=max(idle,vec.at(i*2+2)-vec.at(i*2+1));
    }
    fout<<busy<<" "<<idle<<endl;
    return 0;
}
