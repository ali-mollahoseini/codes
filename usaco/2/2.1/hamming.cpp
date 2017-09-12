/*
ID: ali.mol1
LANG: C++
TASK: hamming
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
int f,b,d,ar[65],cntr;
set<int> st;
#define inf 1000*1000*1000
ifstream fin ("hamming.in");
ofstream fout ("hamming.out");
int distanceh(int a,int b){
    int ans=0;
    while(a!=0||b!=0){
        if(a%2!=b%2){
            ans++;
        }
        a/=2;
        b/=2;
    }
    return ans;
}
int poww(int a,int b){
    int ans=1;
    while(b){
        ans*=a;
        b--;
    }
    return ans;
}
int main (){
    fin>>f>>b>>d;
    int lim= 1 << b+1;
    for(int i=0;i<f;i++){
        for(int j=0;j<lim;j++){
            bool tf=1;
            for(int k=0;k<cntr;k++){
                if(distanceh(j,ar[k])<d){
                    tf=0;
                    break;
                }

            }
            if(tf==1){
                ar[cntr]=j;
                cntr++;
                break;
            }
        }
    }
    for(int i=1;i<=f;i++){
        fout<<ar[i-1];
        if(i!=f&i%10!=0){
            fout<<" ";
        }
        if(i%10==0||i==f){
            fout<<endl;
        }
    }
}
