/*
ID: ali.mol1
LANG: C++
TASK: money
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
const int MX1=1000*10+100;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("money.in");
ofstream fout ("money.out");

ll n,v,ways[MX1][30],types[30];
string s;
map<string,bool> mp;
int main (){
    int i=0;
    fin>>v>>n;
    for(int i =0;i<v;i++){
        fin>>types[i];
    }
    for(int i =0;i<v;i++){
        ways[0][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v;j++){
            ll x=0,y=0;
            if(j!=0){
                x=ways[i][j-1];
            }
            if(i>=types[j]){
                y=ways[i-types[j]][j];
            }
            ways[i][j]=x+y;
        }
    }
    fout<<ways[n][v-1]<<endl;
}
