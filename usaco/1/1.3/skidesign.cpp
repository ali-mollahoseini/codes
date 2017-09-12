/*
ID: ali.mol1
LANG: C++
TASK: skidesign
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=1000+10;
#define inf 1000*1000*1000
ofstream fout ("skidesign.out");
ifstream fin ("skidesign.in");


int n,ar[MX1],mn=inf,baze[MX1];


bool kochektar(int a,int b){
    return (a>b);
}


int main (){
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>ar[i];
        baze[ar[i]]++;
    }
    for (int l=0;l<100-16;l++){


            int r=l+17;
            int tmp=0;
            for (int i=0;i<n;i++){

                if (ar[i]<l){
                    tmp+=(l-ar[i])*(l-ar[i]);
                }else if(ar[i]>r){
                    tmp+=(ar[i]-r)*(ar[i]-r);
                }
            }
            mn=min(tmp,mn);
    }
    fout<<mn<<endl;
}
