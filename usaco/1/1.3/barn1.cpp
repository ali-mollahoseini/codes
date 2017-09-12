/*
ID: ali.mol1
LANG: C++
TASK: barn1
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
ofstream fout ("barn1.out");
ifstream fin ("barn1.in");
int s,c,m,sum;
int ar[MX1],ar2[MX1],mxa;
bool kochektar(int a,int b){
    return (a>b);
}
int main (){
    fin>>m>>s>>c;
    cout<<c;
    for(int i=0;i<c;i++){
        int tmp;
        fin>>tmp;
        ar[i]=tmp;
        cout<<tmp<<" ";
    }
    sort(ar,ar+c);
    cout<<ar[c-1]<<" "<<ar[0]<<endl;;
    sum=ar[c-1]-ar[0]+1;
    cout<<sum;
    for(int i=0;i<c-1;i++){
        ar2[i]=ar[i+1]-ar[i]-1;
    }
    sort(ar2,ar2+c-1,kochektar);
    m--;
    for(int i=0;i<c-1;i++){
        if(m){
            sum-=ar2[i];
            m--;
        }else break;
    }
    fout<<sum<<endl;
}
