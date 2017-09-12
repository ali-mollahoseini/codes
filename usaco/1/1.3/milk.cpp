/*
ID: ali.mol1
LANG: C++
TASK: milk
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int MX1=1000+10;
ofstream fout ("milk.out");
ifstream fin ("milk.in");
int n,u,sum;
int ar[MX1],mxa;
int main (){
    fin>>u>>n;
    for(int i=0;i<n;i++){
        int a;
        fin>>ar[i];
        mxa=max(mxa,a);
    }
    cout<<mxa;
    for(int i=0;i<mxa+1;i++){
            if(ar[i]>0){
            }
                if(ar[i]>u&&u !=0){
                    sum+=i*u;
                    u=0;
                }else{
                    int a=i,b=ar[i];
                    sum+=a*b;
                    u-=b;
            }
            if(u==0){
                break;
            }
            //fout<<it->first<<" "<<it->second<<endl;
    }

    fout<<sum<<endl;
}
