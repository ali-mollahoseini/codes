/*
ID: ali.mol1
LANG: C++
TASK: humble
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
ifstream fin ("humble.in");
ofstream fout ("humble.out");

int parent[MX1];
int min_e[MX1];
bool used[MX1];
int n,sum;
vector<pair<int,int> > adj[MX1];


void inp();
void find_mst();


int main (){
    inp();
}



void inp(){
    fin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            fin>>tmp;
            if(i!=j){
                adj[i].push_back(make_pair(j,tmp));
                adj[j].push_back(make_pair(i,tmp));
            }
        }
    }
}
