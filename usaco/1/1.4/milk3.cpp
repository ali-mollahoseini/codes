/*
ID: ali.mol1
LANG: C++
TASK: milk3
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
const int MX1=200;
#define inf 1000*1000*1000
ifstream fin ("milk3.in");
ofstream fout ("milk3.out");


int vol[3];
set<int> st;
bool mark [MX1][MX1][MX1];
void ans(int nex[]){
    if(mark[nex[0]][nex[1]][nex[2]]) return;
    mark[nex[0]][nex[1]][nex[2]]=1;
    if(nex[0]==0){
        st.insert(nex[2]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        int tmp=min(nex[i],vol[j]-nex[j]);
            nex[j]+=tmp;
            nex[i]-=tmp;
            ans(nex);
            nex[j]-=tmp;
            nex[i]+=tmp;
        }
    }
    return;
}
int main (){
    fin>>vol[0]>>vol[1]>>vol[2];
    int tmp[3]={0,0,vol[2]};
    ans(tmp);
    for(set<int>::iterator it = st.begin();it !=st.end();it++){
        if(it!=st.begin()){
            fout<<" ";
        }
        fout<<*it;
    }
    fout<<endl;
}
